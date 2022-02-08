/*! \file
  Contains an implementation of Potokashi class's methods
  \see ./potokashi.hpp
 */

#include "./potokashi.hpp"
// includes for rand() and srand()
#include <cstdlib>
#include <cstring>
#include <ctime>
// Returns the tile number
const int Potokashi::operator[](const int position) const {
  return this->_tiles[position];
}

// Checks if potokashi fields are equal
const bool Potokashi::operator==(const Potokashi &compareTo) const {
  return std::equal(std::begin(_tiles), std::end(_tiles),
                    std::begin(compareTo._tiles));
}

const bool Potokashi::operator!=(const Potokashi &compareTo) const {
  return !(*this == compareTo);
}

std::ostream &operator<<(std::ostream &out, const Potokashi &potokashi) {
  for (int i = 0; i < 16; i++) {
    out << potokashi._tiles[i] << " ";
  }
  return out;
}

std::istream &operator>>(std::istream &in, Potokashi &potokashi) {
  int position, direction;
  in >> position;
  in >> direction;

  potokashi.moveTile(position, direction);
  return in;
}

// A default constructor which generates random potokashi field
Potokashi::Potokashi() {

  std::srand(time(0));
  int used[15] = {0};
  int index;
  for (int position = 0; position < 16; position++) {
    do
      // generate a random number in range 0-15
      index = rand() % 16;
    while (used[index] == 1);
    // mark it as used, so no repeats will be allowed
    used[index] = 1;
    _tiles[position] = index;
  }
}

Potokashi::Potokashi(const Potokashi &other) {
  // because, uh, arrays are not assignable in C++. Alright, a memory-copy then.
  std::memcpy(_tiles, other._tiles, 16 * sizeof(int));
}

Potokashi::Potokashi(const std::vector<int> tiles) {
  if (tiles.size() != 16)
    throw("Incorrect vector size in Potokashi constructor.");
  // Copying all vector elements to Tiles array.
  std::copy(tiles.begin(), tiles.end() + sizeof(int), _tiles);
}

// Checks if potokashi field is correct (as in "solved")
const bool Potokashi::checkCorrectness() const {
  for (int position = 0; position < 16; position++) {
    /* Simple algorithm - for the layout to be correct,
      encoded position and value of the tile should be equal
    */
    if (_tiles[position] != position)
      return false;
  }
  return true;
}

/*
Function that moves tile and returns true, if it is possible. Returns false
otherwise.
Direction argument can accept following values:
0 - up; 1 - down; 2 - left; 3 - right;*/
bool Potokashi::moveTile(const int position, const int direction) {
  // check if input is correct
  if (position < 0 || position > 15)
    return false;

  int newPosition = -1;

  switch (direction) {
  case 0: {
    // We can't move the tile up if it's located on the highest row
    if (position < 4)
      return false;
    newPosition = position - 4;
    break;
  }

  case 1: {
    // We can't move the tile down if it's located on the lowest row
    if (position > 11)
      return false;
    newPosition = position + 4;
    break;
  }

  case 2: {
    /*We can't move the tile left if it's located in the first column
    We can divide the position by 4 and check if there's any remainder. If
    there is, it means we're in the first column*/
    if (position % 4 == 0)
      return false;
    newPosition = position - 1;
    break;
  }

  case 3: {
    /*We can't move the tile right if it's located in the last column
      We can divide the position by 4 and check if there's any remainder. If
      the remainder is 3, it means we're in the last column*/
    if (position % 4 == 3)
      return false;
    newPosition = position + 1;
    break;
  }
  };

  // check if the switch executed correctly
  if (newPosition < 0)
    return false;
  // check if the newPosition is not occupied by a tile
  if (this->_tiles[newPosition] != 0)
    return false;
  // swap the tiles themselves
  _tiles[newPosition] = _tiles[position];
  _tiles[position] = 0;
  return true;
}

std::vector<int> Potokashi::getTiles() const {
  std::vector<int> tiles;
  // copy exactly 16 ints from the class's Tiles array to the new tiles vector
  // and return it.
  //using _tiles[16] intentionally, because otherwise the .insert ignores the last element.
  tiles.insert(tiles.end(), &_tiles[0], &_tiles[16]);
  return tiles;
}
