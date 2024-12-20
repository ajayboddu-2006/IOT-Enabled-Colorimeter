# IOT-Enabled Colorimeter

This repository contains the source code, documentation, and schematics for a IOT - Enabled Colorimeter, a device used to measure the concentration of colored compounds in solutions by analyzing their absorbance based on different wavelengths. This project is ideal for scientific applications, educational purposes, and DIY experiments.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Components](#components)
- [Circuit Design](#circuit-design)
- [Applications](#applications)

## Overview

A colorimeter is a laboratory device used to measure the absorbance of light at specific wavelengths in a given solution. Colorimetry is based on `Beer-Lambert’s law`, which states that the amount of light absorbed by a colored solution is directly proportional to the solution’s concentration and the length of the light path through it. When light passes through a sample solution, part of it is absorbed, while the remaining light is transmitted. By comparing the color intensity of a solute in the sample solution to that of a reference solution with a known solute concentration, we can estimate the concentration of the colored solute in the sample. Colorimeters are commonly used in fields such as water analysis, environmental analysis, and laboratory research.

Colorimeters, if accessible to households, could be used for practical applications like food quality control, water testing, and gardening. For instance, they could help ensure the freshness of fruits based on their color, test the purity of tap water, or analyze soil nutrients for home gardening. These applications could contribute to health, food safety, and environmental conservation efforts at a personal level.

![Colorimeter](./image.jpg)

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
- **Push Buttons**: For user Interaction
- **Potentiometer**: For generating different wavelengths of light.
  

## Circuit Design

The circuit uses an RGB-LED light source directed toward a cuvette through the convex lens and slit, containing the sample solution. The RGB led is used to generate different wavelengths of Light source controlled using Potentiometer. The different wavelengths of light source are incident on the cuvette. The solution absorbs some of the wavelegths based on its characteristics. And the remaining light is transmitted through the solution and is detected by LDR sensor. Based on the Beer Lambert's Law, the microcontroller computes the absorbance and the concentration of the solution. And the wavelength, Absorbance and Concentration are displayed on the I2C LCD Display for visualization. There are are three Push buttons for User interaction, for the functionalities to perform Zero Analysis of Standard Solution, Calibration and Reset respectively. This IOT-Enabled Colorimeter is used to analyze the Concentration and Absorbance of the solution based on the Beer-Lambert's Law, with extended Accuracy by enabling Calibration. It is used to perform Food Quality Analysis, Environmenta Analysis and Water Quality Analysis. 

![Circuit_Colorimeter](./Circuit.jpg)

Below is the image of the setup of the Colorimeter:

![Colorimeter_image](./colorimeter_image.jpg)

## Applications:

Colorimeters are widely used in various fields for accurate color measurement and analysis. Here are some key applications:

**1. Chemical Analysis**: Used in labs to determine the concentration of substances in solutions by measuring absorbance and transmittance.

**2. Food and Beverage**: Ensures consistent color in products like juices, sauces, and beverages, which is essential for quality control.

**3. Environmental Testing**: Helps monitor pollutants in water by measuring color changes in samples, indicating the presence of contaminants.

**4. Medical Diagnostics**: Used in clinical tests to analyze blood or urine samples for chemical concentrations.

**5. Textile and Paint Industries**: Ensures uniformity in color shades and batches, critical for maintaining brand consistency and quality.

**6. Agriculture**: Analyzes soil samples and crop health based on color variation to determine nutrient deficiencies.

Colorimeters provide reliable color quantification, making them invaluable across scientific, industrial, and quality-control applications.
