# Spinlock Engine
The Spinlock Engine is a high-performance C++ game engine built from scratch for 2d and 3d game development. It is designed for maximum performance, strict modularity, and zero bloat. Every core component exists for a reason, and nothing extra is forced on your game. 

## Core Philosophy

The engine is divided into two layers:
- **Core** - Foundational features that almost every game needs (memory, math, containers, ECS, job scheduler, virtual file system, event bus, console, serialization, …) lives here. It is tightly integrated but carefully organized so that individual subsystems remain testable and replaceable.
- **Modules** - Optional feature sets that you enable per project: rendering (2D/3D), audio, physics, inventory, cards, platform services, and more. Any module can be enabled or disabled without affecting `core`, and each module is fully self-contained.

## Key Features

- **Data Oriented ECS** - The engine enforces a data-oriented ECS architecture, where entities are represented by unique IDs and components are stored in contiguous memory buffers. Components are stored together in memory for efficient iteration and cache locality, and systems are automatically scheduled and executed in parallel using a dependency graph.
- **Virtual Memory System** and **Virtual File System** - Memory and File operations are all fully sandboxed, preventing any unauthorized access or corruption. 
- **Multi-platform support** - The Platform Abstraction Layer (PAL) provides a simple, platform-independent interface for the engine, allowing it to run on multiple platforms without modification.

## Engine Goals
- Build optional engine features as distinct modules that can be easily swapped out, extended, or replaced.
- Primarily optimize for low end hardware.

## Building

The project uses CMake with [presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html). You need CMake 3.20+ and a C++20 compiler (clang++ is configured by default).

### Debug

Configure, build, and run tests:

```bash
cmake --preset debug
cmake --build --preset debug
./build/debug/bin/test_main
```

Artifacts:

- Static library: `build/debug/lib/libspinlock.a`
- Test executable: `build/debug/bin/test_main`

### Release

```bash
cmake --preset release
cmake --build --preset release
./build/release/bin/test_main
```

Artifacts:

- Static library: `build/release/lib/libspinlock.a`
- Test executable: `build/release/bin/test_main`

### Editor support

After configuring Debug, point your language server at the generated compile commands:

```bash
ln -sf build/debug/compile_commands.json compile_commands.json
```
