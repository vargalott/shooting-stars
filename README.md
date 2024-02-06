# shooting-stars

[![Build](https://github.com/vargalott/shooting-stars/actions/workflows/build.yml/badge.svg)](https://github.com/vargalott/shooting-stars/actions/workflows/build.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

shooting-stars - a simple graphical app that creates an everlasting stream of colored stars.

<img src="app.gif" width="750"/>

## Build

1. Clone this project and then cd to the project folder;

2. Init the sfml git submodule:
```
$ git submodule init
$ git submodule update --init --recursive

OR

$ task init
```

3. Configure the project using CMake:
```
$ cmake -B ./build -G <preferred generator> -DCMAKE_BUILD_TYPE=<Debug|Release>

OR

$ task configure_<debug|release> -- <preferred generator>
```

4. Then run build command:
```
$ cmake --build ./build --config <Debug|Release>

OR

$ task build_<debug|release>
```

5. You've done! The builded binary file available in the build directory, you can run it using:
```
$ task run
```

## License

This project is licensed under the [MIT License](LICENSE).

## Credits

My thanks to the developers of the [SFML](https://github.com/SFML/SFML).
