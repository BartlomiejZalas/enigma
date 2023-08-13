# Enigma Machine

The project is the software implementation of a cipher device developed and used by Germans during World War II. The implemented solution refers to model M3.

## Requirements

- CMake <= 3.14

## Usage

### Run

To build and run the program execute the script located in the main project directory:

```bash
./run.sh
```
After successfull build the project can be executed as binary from the build directory:
```bash
./build/enigma
```

### Test
To build and run the tests execute the script located in the main project directory:

```bash
./test.sh
```

## Configuration

The program by default uses below Enigma setup. It can be changed by editing `main.cpp` file. List of possible wiring configuration can be found [here](https://www.cryptomuseum.com/crypto/enigma/wiring.htm#m3).

### Rotors

| Rotor   | Wiring                     |  Initial offset |
|---------|----------------------------|-----------------|
| I       | EKMFLGDQVZNTOWYHXUSPAIBRCJ | A               |
| II      | AJDKSIRUXBLHWTMCQGZNPYFVOE | A               |
| III     | BDFHJLCPRTXVZNYEIWGAKMUSQO | A               |

### Plugboard

- `A ↔ B`

### Reflector

UKW-B with wiring `YRUHQSLDPXNGOKMIEBFZCWVJAT`.

