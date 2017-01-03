## Rundown
A C++14 implementation of the Boost::Signals2 library.

This is an implementation of a Signals and Slots system. Signals are callbacks
with potentially multiple targets. A Signal can be emitted by calling is with
parameters that are to be passed onto the targets. A Slot's lifetime can be
managed by tracking objects involved with the Slot, if one of these tracked
objects is destroyed, the Slot is disabled and will no longer be called. Return
values from multiple Slots have to be combined in some way in order to be
returned by a Signal, the user is allowed to override the default behavior of
returning the return value of the last Slot called by providing a new Combiner
type.

## Code Example
    int foo(char c, double d) { return 7; }

    sig::Slot<int(char, double)> slot_1 = [](char, double) { return 3; };
    sig::Slot<int(char, double)> slot_2{foo};

    auto bar = std::make_shared<int>{5};
    slot_2.track(bar);

    sig::Signal<int(char, double)> signal_1;
    signal_1.connect(slot_1);
    signal_1.connect(slot_2);

    auto optional_result = signal_1('f', 3.2);

    ASSERT_TRUE(optional_result);
    EXPECT_EQ(7, *optional_result);

    bar.reset();
    optional_result = signal_1('g', 7.2);

    ASSERT_TRUE(optional_result);
    EXPECT_EQ(3, *optional_result);


## Motivation
This particular implementation was largly created for personal practice. It is
also used by the [TWidgets Framework](
https://github.com/a-n-t-h-o-n-y/TWidgets).

## Installation
Use cmake to setup the build environment by running `cmake ..` from the build/
directory. From here you can run `make tests` to create the test executable and
`make install` to install the headers and static library to a location specified
in [CMakeLists.txt](CMakeLists.txt).

## Wiki
This project utilizes the [GitHub wiki pages](
https://github.com/a-n-t-h-o-n-y/Signals/wiki). These contain more information
on the specifics of using the library.

## Documentation
Doxygen documentation can be found [here](
https://a-n-t-h-o-n-y.github.io/Signals/).

The documentation can also be generated by running `make docs`, output will
appear in the docs/ folder.

## Tests
This library uses the google testing framework. After setting up the build/
directory with cmake, run `make test`. The test executable will be create in
the bin/ directory.

## Contributions
All help is welcome, add your contribution to this project by creating a pull
request. Append your name to the [CONTRIBUTORS.md](CONTRIBUTORS.md) file as
well. Issues and questions can be directed to the GitHub issue tracker.

## License
This software is distributed under the [MIT License](LICENSE.txt).

![alt_text](docs/signals.png "Signals Logo")