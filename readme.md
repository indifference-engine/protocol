# Protocol

C library to read and write a streaming binary protocol.

## Data Structure

The protocol is a stream of commands:

- An unsigned 32-bit integer which is greater than zero specifying the length of
  the command's payload in bytes.
- The bytes representing the corresponding command's payload.
- Repeat until the end of the stream.

All fields are little endian.

## Usage

### Project Level

Your application's build pipeline will need to be configured to compile each C
file in the [src](./src) directory and recompile every C file should any H files
change.  Then, include each H file in the same directory to make its
corresponding function available.

### Assumptions

- The compilation environment supports C99.
- The runtime environment is little-endian.  This may change if a big-endian
  test environment becomes available trivially.

### Functions

| Name            | Description                                                          |
| --------------- | -------------------------------------------------------------------- |
| `write_u8`      | Attempts to write one or more unsigned 8-bit integers to a buffer.   |
| `write_u16`     | Attempts to write one or more unsigned 16-bit integers to a buffer.  |
| `write_u32`     | Attempts to write one or more unsigned 32-bit integers to a buffer.  |
| `write_u64`     | Attempts to write one or more unsigned 64-bit integers to a buffer.  |
| `write_s8`      | Attempts to write one or more signed 8-bit integers to a buffer.     |
| `write_s16`     | Attempts to write one or more signed 16-bit integers to a buffer.    |
| `write_s32`     | Attempts to write one or more signed 32-bit integers to a buffer.    |
| `write_s64`     | Attempts to write one or more signed 64-bit integers to a buffer.    |
| `write_f32`     | Attempts to write one or more 32-bit IEEE 754 floats to a buffer.    |
| `write_f64`     | Attempts to write one or more 64-bit IEEE 754 floats to a buffer.    |
| `read_u8`       | Attempts to read one or more unsigned 8-bit integers from a buffer.  |
| `read_u16`      | Attempts to read one or more unsigned 16-bit integers from a buffer. |
| `read_u32`      | Attempts to read one or more unsigned 32-bit integers from a buffer. |
| `read_u64`      | Attempts to read one or more unsigned 64-bit integers from a buffer. |
| `read_s8`       | Attempts to read one or more signed 8-bit integers from a buffer.    |
| `read_s16`      | Attempts to read one or more signed 16-bit integers from a buffer.   |
| `read_s32`      | Attempts to read one or more signed 32-bit integers from a buffer.   |
| `read_s64`      | Attempts to read one or more signed 64-bit integers from a buffer.   |
| `read_f32`      | Attempts to read one or more 32-bit IEEE 754 floats from a buffer.   |
| `read_f64`      | Attempts to read one or more 64-bit IEEE 754 floats from a buffer.   |
| `read_commands` | Attempts to read a stream of commands.                               |

## Tests

Execute `make` to run the test suite.

### Dependencies

- Make.
- MinGW-GCC for Windows, Clang for all other platforms.
- Bash.
