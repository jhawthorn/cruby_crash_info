# frozen_string_literal: true

require "test_helper"

class TestCrubyCrashInfo < Minitest::Test
  def test_info_can_be_set_and_retrieved
    CRubyCrashInfo.info = "extra info"
    assert_equal "extra info", CRubyCrashInfo.info
  end

  def test_info_is_reported_on_crash
    p, c = IO.pipe
    opts = {
      err: c
    }
    pid = Process.spawn(RbConfig.ruby, "-I", "#{__dir__}/../lib", "-e", <<~RUBY, opts)
      require "cruby_crash_info"
      require "fiddle"

      CRubyCrashInfo.info = "Important extra info"

      # Invalid pointer deference! Should SEGV
      Fiddle::Pointer[0x1000][0]
    RUBY
    c.close

    Process.waitpid(pid)

    err = p.read
    assert_includes err, "Important extra info"
  end
end
