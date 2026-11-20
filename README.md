# Ecosystem Simulator

Ecosystem simulation in C++ on a 10x10 grid, built with the Singleton, Factory and Strategy patterns.

## Description

Console simulation of an ecosystem where herbivores, carnivores and omnivores live on a 10x10 grid with water, plants and meat as resources. In each iteration creatures move, eat according to their diet, lose energy and age, and can reproduce with nearby creatures of the same type. When a creature runs out of energy it dies and leaves meat on the grid, while resources degrade over time. Every iteration prints the grid and the events that happened.

## Features

- 10x10 grid stored as a dynamic two-dimensional array of elements
- Three types of creatures (herbivore, carnivore and omnivore) with age and energy level
- Three types of resources (water, plants and meat) that degrade over time
- Diet rules: each creature can only consume the resources its strategy allows
- Reproduction between compatible creatures when both have enough energy
- Creatures that die from lack of energy turn into a meat resource
- Event log per iteration (movements, feeding, reproduction and deaths)
- Simulation of up to 50 iterations that stops when no creatures are left

## Design Patterns

| Pattern | Where |
|---|---|
| Singleton | `Entorno`: a single shared environment (grid) |
| Factory | `FabricaCriaturas` and `FabricaElemento` create creatures and resources |
| Strategy | Feeding (`AlimentacionH`, `AlimentacionC`, `AlimentacionO`), movement (`MovimientoAleatorio`) and reproduction (`ReproduccionSimple`) |

It also uses inheritance and polymorphism (`Elemento` → `Criatura` / `Recurso`), STL containers and lambdas.

## Tech Stack

- **Language:** C++
- **Concepts:** OOP, design patterns, STL
- **IDE:** Visual Studio 2022

## How to Run

### Prerequisites

- Windows with Visual Studio 2022 and the "Desktop development with C++" workload

### Steps

1. Clone the repository.
2. Open `SimulEcosistemaMatriz.sln` in Visual Studio.
3. Press **Ctrl+F5** (Start Without Debugging).

The console prints the grid and the events of each iteration, with a 5-second pause between iterations.

## Team

Built with [Alejandro Calderón](https://github.com/AleCalderon1711).
