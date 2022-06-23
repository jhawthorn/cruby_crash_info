# CrubyCrashInfo

This adds the abilitiy to add extra info to the end of Ruby's bug/crash reports.

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'cruby_crash_info'
```

And then execute:

    $ bundle install

## Usage

Assign a String to `CRubyCrashInfo.info`.
This can be done multiple times and only the latest assigned info will be used.

```
CRubyCrashInfo.info = <<EOF
Extra info to print!
request_id: #{rand(9999999999)}
EOF
```

**DEMO:** cause a crash

``` ruby
require "fiddle"
Fiddle.dlunwrap(0x1234).to_s # SEGV
```

```
test.rb:9: [BUG] Segmentation fault at 0x0000000000001244
ruby 3.1.0p0 (2021-12-25 revision fb4df44d16) [x86_64-linux]

-- Control frame information -----------------------------------------------
c:0003 p:---- s:0010 e:000009 CFUNC  :to_s
c:0002 p:0054 s:0006 e:000005 EVAL   test.rb:9 [FINISH]
c:0001 p:0000 s:0003 E:0021a0 (none) [FINISH]

-------------------8<-----------------
7ffcc7f0b000-7ffcc7f0d000 r-xp 00000000 00:00 0                          [vdso]
ffffffffff600000-ffffffffff601000 --xp 00000000 00:00 0                  [vsyscall]


 * Extra crash info:
Extra info to print!
request_id: 4843151088

```

## Development

After checking out the repo, run `bin/setup` to install dependencies. Then, run `rake test` to run the tests. You can also run `bin/console` for an interactive prompt that will allow you to experiment.

To install this gem onto your local machine, run `bundle exec rake install`. To release a new version, update the version number in `version.rb`, and then run `bundle exec rake release`, which will create a git tag for the version, push git commits and the created tag, and push the `.gem` file to [rubygems.org](https://rubygems.org).

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/jhawthorn/cruby_crash_info. This project is intended to be a safe, welcoming space for collaboration, and contributors are expected to adhere to the [code of conduct](https://github.com/jhawthorn/cruby_crash_info/blob/main/CODE_OF_CONDUCT.md).

## License

The gem is available as open source under the terms of the [MIT License](https://opensource.org/licenses/MIT).

## Code of Conduct

Everyone interacting in the CrubyCrashInfo project's codebases, issue trackers, chat rooms and mailing lists is expected to follow the [code of conduct](https://github.com/jhawthorn/cruby_crash_info/blob/main/CODE_OF_CONDUCT.md).
