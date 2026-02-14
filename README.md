# Clinschoten

A lightweight C logging library.

[![CI](https://github.com/YOUR_USERNAME/clinschoten/actions/workflows/ci.yml/badge.svg)](https://github.com/YOUR_USERNAME/clinschoten/actions/workflows/ci.yml)

## Features

- Lightweight static library
- Multiple log levels (DEBUG, INFO, WARNING, ERROR, CRITICAL)
- Configurable log level filtering
- C99 standard compliant

## Building

### Prerequisites

- CMake 3.10 or higher
- C compiler with C99 support (GCC, Clang, MSVC)

### Build Instructions

```bash
# Configure
cmake -B build -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build build

# Install (optional)
sudo cmake --install build
```

## Testing

The project includes a comprehensive test suite using the Unity test framework.

### Running Tests

```bash
# Configure with testing enabled
cmake -B build -DCMAKE_BUILD_TYPE=Debug -DCLN_BUILD_TESTING=ON

# Build
cmake --build build

# Run tests
cd build && ctest --output-on-failure
```

### Test Structure

- `tests/unity/` - Unity test framework
- `tests/test_logger.c` - Logger functionality tests
- `tests/test_runner.c` - Test runner main file

### Test Coverage

The test suite covers:
- Logger creation and initialization
- All log levels (DEBUG, INFO, WARNING, ERROR, CRITICAL)
- Log level filtering
- Constant definitions
- Error handling

## Continuous Integration

This project uses GitHub Actions for continuous integration. Tests run automatically on:
- Every push to the `main` branch
- Every pull request targeting `main`

The CI pipeline:
- Tests on multiple platforms (Ubuntu, macOS)
- Tests both Debug and Release builds
- Runs the full test suite with output on failure

## Usage

```c
#include <clinschoten/logger.h>
#include <clinschoten/constants.h>

int main(void)
{
    ClnLogger logger;
    logger.name = "MyApp";
    
    ClnLogger__log(&logger, INFO_LL, "Application started");
    ClnLogger__log(&logger, WARNING_LL, "This is a warning");
    ClnLogger__log(&logger, ERROR_LL, "An error occurred");
    
    return 0;
}
```

### Log Levels

- `NOT_SET_LL` (0) - Not set
- `DEBUG_LL` (1) - Debug messages
- `INFO_LL` (2) - Informational messages
- `WARNING_LL` (3) - Warning messages
- `ERROR_LL` (4) - Error messages
- `CRITICAL_LL` (5) - Critical errors

### Configuration

The logging level can be configured at compile time using CMake:

```bash
cmake -B build -DCLN_LOG_LEVEL=1  # Set to DEBUG level
```

## License

See [LICENSE](LICENSE) file for details.
