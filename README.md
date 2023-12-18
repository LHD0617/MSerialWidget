# Serial Port Tool using Qt

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Building](#building)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Introduction

This project is a serial port tool developed using Qt, providing a user interface to interact with serial ports. It allows users to open, close, and switch between available serial ports, with configurable parameters such as baud rate, data bits, parity, and stop bits.

## Features

- Automatic refreshing of available serial ports
- Dynamic update of port list in the UI
- User-friendly interface for configuring serial port parameters
- Open and close serial ports with a single click
- Real-time logging of port status

## Getting Started

### Prerequisites

- Qt 5 or later installed
- C++ development environment

### Building

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/serial-port-tool.git
   ```

2. Open the project in Qt Creator or use qmake to build the project:

    ```bash
    qmake
    make
   ```

## Usage

1. Launch the application after building.
2. The available serial ports will be automatically detected and listed.
3. Configure the desired parameters (baud rate, data bits, parity, stop bits).
4. Click the "打开串口" button to open the selected serial port.
5. To close the serial port, click the "关闭串口" button.

## Contributing

Contributions are welcome! Feel free to open issues or pull requests.

## License

This project is licensed under the MIT License.

## Acknowledgments

Special thanks to 满心欢喜 for the initial contribution.
Feel free to customize the content further according to your project's specific details.
