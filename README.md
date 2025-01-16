# Cleaning Equipment Rental Price Calculator

This C program calculates rental prices for four types of cleaning equipment:
1. Carpet blower
2. Carpet cleaner
3. Carpet extractor with heater
4. Hard flooring cleaner

## Features
- Computes hourly, daily, and weekly rental prices.
- Optimizes rate selection for cost-effectiveness.
- Alerts users about invalid input hours.

## Usage
1. Run the program.
2. Select an equipment type (1–4).
3. Enter rental days and hours.
4. View the calculated total charge.

## Rates
| Equipment                  | 4-Hour Rate | Daily Rate | Weekly Rate |
|----------------------------|-------------|------------|-------------|
| Carpet blower              | $7          | $10        | $40         |
| Carpet cleaner             | $27         | $39        | $156        |
| Carpet extractor with heater | $61       | $87        | $348        |
| Hard flooring cleaner      | $59         | $84        | $336        |

## Requirements
- C Compiler (e.g., GCC)

## How to Compile and Run
1. Compile the program:
   ```bash
   gcc rental_calculator.c -o rental_calculator
