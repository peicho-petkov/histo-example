# histo-example

A simple C project demonstrating the creation and use of 1D histograms (Version v0.1).

## Features

* **`hist1d` library**: Create, fill, scale, normalize, and output 1D histograms.
* **Example programs**: `run-the-show` for simulating events and `histo1d-test` for testing histogram functions.
* **Lightweight and portable**: Pure C implementation with CMake build system.
* **Optional plotting**: Generate data files compatible with `gnuplot` for visualizing histograms.

## Directory Structure

```
├── CMakeLists.txt         # Build configuration (CMake 3.22+)
├── include/               # Public headers
│   ├── histogram1d.h      # 1D histogram API
│   └── utils.h            # Utility functions (random number generator)
├── src/                   # Library and examples
│   ├── histogram1d.c      # `hist1d` library implementation
│   ├── utils.c            # Utility implementation
│   ├── main.c             # `run-the-show` example
│   └── histo1d-test.c     # `histo1d-test` example
├── .gitignore             # Ignore build artifacts and temp files
└── README.md              # This file
```

## Requirements

* A C compiler with C99 support (e.g., GCC, Clang)
* CMake 3.22 or newer
* (Optional) `gnuplot` for plotting histogram outputs

## Building

```bash
# Clone the repository
 git clone https://github.com/peicho-petkov/histo-example.git
 cd histo-example

 # Create a build directory and configure
 mkdir build && cd build
 cmake ..

 # Build the library and executables
 make
```

## Installation

After building, you can install the library and executables system-wide with:

```bash
# In the build directory
sudo make install
```

This copies headers and libraries to your system include and lib paths, and makes `run-the-show` and `histo1d-test` available on your PATH.

## Usage

### `run-the-show`

```bash
# Default: 100000 events
./run-the-show [Nevents]
```

* **`Nevents`**: (Optional) Number of random events to generate. Default is 100000.

This program simulates pin placements on a wire and prints a histogram of pin distribution to the console.

### `histo1d-test`

```bash
./histo1d-test
```

This program:

1. Generates a 1D histogram of random data with default parameters.
2. Prints summary statistics and bin counts to the console.
3. Writes two output files in the current directory:

   * `histogram1d-test.txt`: Raw bin counts
   * `histogram1d-test-normalized.txt`: Normalized counts (unit area)

## Plotting with gnuplot

After running `histo1d-test`, you can visualize the normalized histogram with a simple gnuplot command:

```bash
gnuplot -e "set terminal png size 800,600; set output 'histogram.png'; plot 'histogram1d-test-normalized.txt' using 1:2 with boxes title 'Histogram'"
```

## Contributing

Bug reports, feature requests, and pull requests are welcome. Please open an issue on the [GitHub issue tracker](https://github.com/peicho-petkov/histo-example/issues).

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

*README updated with assistance from ChatGPT.*
