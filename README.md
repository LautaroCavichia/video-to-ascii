# Video to ASCII Converter (CLI)

This C++ program converts a video into an ASCII animation in the terminal using OpenCV.

![Screenshot 2025-02-08 at 08 59 43](https://github.com/user-attachments/assets/10680537-0b7e-4012-9144-ec939e6fa5af)


## Requirements

- OpenCV 4 installed
- C++ compiler (g++)
- CMake (optional for building)

## Installation & Compilation

### Using g++

Clone the repository and compile the program:

```sh
g++ -o video_to_ascii video_to_ascii.cpp `pkg-config --cflags --libs opencv4`
```

### Using CMake

1. Create a `build` directory:
   ```sh
   mkdir build && cd build
   ```
2. Run CMake:
   ```sh
   cmake ..
   ```
3. Compile:
   ```sh
   make
   ```

This will generate the `video_to_ascii` executable inside the `build` directory.

## Usage

Run the executable with a video file:

```sh
./video_to_ascii <video_absolute_path> [ascii_width]
```

### Example:
```sh
./video_to_ascii path_to/sample.mp4 100
```

- `<video_absolute_path>`: Path to the video file
- `[ascii_width]` (optional): Adjusts the width of the ASCII output

## Notes
- Ensure OpenCV is installed and accessible via `pkg-config`.
- The program dynamically resizes the ASCII output based on video dimensions.

## License
MIT License

