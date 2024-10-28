# Colorimeter Project

This repository contains the source code, documentation, and schematics for a IOT - Enabled Colorimeter, a device used to measure the concentration of colored compounds in solutions by analyzing their absorbance. This project is ideal for scientific applications, educational purposes, and DIY experiments.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Components](#components)
- [Circuit Design](#circuit-design)
- [Software](#software)
- [Setup & Usage](#setup--usage)
- [Applications](#applications)
- [Contributing](#contributing)
- [License](#license)

## Overview

A colorimeter measures the absorbance of specific wavelengths of light by a sample to determine the concentration of compounds in a solution. This project provides a simple yet effective way to analyze the properties of various substances through light analysis.

## Features

- **Wavelength Selection**: Choose from multiple wavelengths for diverse compound analysis.
- **Data Visualization**: Real-time display of absorbance levels.
- **Calibration**: Built-in calibration features to enhance accuracy.
- **Portable and Cost-effective**: Designed for affordability and portability for lab or field use.

## Components

- **RGB LED Light Source**: For various wavelengths (red, green, blue).
- **LDR Sensor**: Detects light transmission through the sample.
- **Arduino UNO**: For processing the signals.
- **I2C LCD Display Module**: Shows the measured values and calibration data.
- **Cuvette Holder**: Holds the sample for measurement.

## Circuit Design

The circuit uses an LED light source directed toward a cuvette containing the sample solution. A photodiode opposite the light source detects the light that passes through the solution. The microcontroller calculates absorbance based on the intensity of the transmitted light.

<!-- You can add an image here if you have a circuit diagram. -->

## Software

The software for this project is written in C++ (Arduino IDE). It performs the following tasks:

1. Controls the LED light source.
2. Reads the photodiode output and calculates the absorbance.
3. Displays data and calibration information on an LCD.

## Setup & Usage

1. **Hardware Setup**: Assemble the circuit according to the provided schematics.
2. **Upload Code**: Upload the Arduino code provided in the `src` folder to the microcontroller.
3. **Calibration**: Place a reference sample in the cuvette holder, and use the calibration function to set the baseline absorbance.
4. **Measurements**: Insert test samples and observe the absorbance values displayed on the screen.

## Applications

This colorimeter can be used for:

- Chemical analysis in laboratories and educational settings.
- Concentration measurement of solutions.
- Experiments in photometry and colorimetry.
