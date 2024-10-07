# Faux planet

## Compile


### Premake
- `git submodule update --init --recursive`
- Install premake5 and put it on your path https://premake.github.io/download
- Run premake5 (e.g. `premake5 gmake2`)
- Compile for your platform (e.g. `make`)
- Run for your platform (e.g. `./bin/Debug-linux/FauxPlanet`)

### CMake
- `git submodule update --init --recursive`
- Install cmake and put it on your path.
- Run cmake (e.g. `cmake -G Ninja .`)
- Compile for your platform (e.g. `ninja`)
- Run (e.g. `./bin/FauxPlanet`)
