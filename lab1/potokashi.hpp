/*! \file
  Defines the Potokashi class (barley-brake game class)
  The class has basic methods to check if the field is done/correct/the player
  won, to move the tile, and to get the tile number at some position.
  Position in this library is encoded by a formula: pos=3x+y, x and y start from 0, so [0, 3].
  \author Pavel Nasevich (fallenchromium@gmail.com)
 */

#include <iostream>
#include <vector>

class Potokashi {
private:
  int _tiles[15];

public:
  /*! Default constructor, randomized field is generated. */
  Potokashi();

  /*! Copying constructor, copies the field from another Potokashi object.
    \param other pointer to a Potokashi object
  */
  Potokashi(const Potokashi &other);

  /*! A potokashi field is constructed from a vector.
    \param tiles vector<int>, size of exactly 16. index is tile's position,
    value is tile's number.
    \throws std::string if the size of the tiles vector is not 16*/
  Potokashi(const std::vector<int> tiles);

  /*! Returns the tile number which is located at the position (taken as an
  argument).
  \param position tile's position. Calculated by a formula: pos=3x+y, where x
  and y are in [0,3] \returns tile's number at the given position*/
  const int operator[](const int position) const;

  /*! Checks if the potokashi field is the same in both objects */
  const bool operator==(const Potokashi &compareTo) const;

  /*! Checks if the potokashi field is NOT the same in both objects */
  const bool operator!=(const Potokashi &compareTo) const;

  /*! Outputs the tile field, as tile numbers separated by spaces, sorted by
  position. */
  friend std::ostream &operator<<(std::ostream &out,
                                  const Potokashi &potokashi);

  /*! Scans two numbers - position of the tile and direction you want to move it
   * to.*/
  friend std::istream &operator>>(std::istream &in, Potokashi &potokashi);

  /*! Checks if you won the game by sorting the field properly (empty tile
   * first, tiles 1-15 afterwards).*/
  const bool checkCorrectness() const;

  /*!  \brief Moves the tile's at position in a direction.
  Returns true and changes the field if it's possible to move the tile,
  returns false otherwise.
  \param position current position of the tile. pos=3x+y, where x and y
  are in [0,3]
  \param direction integer, represents direction. (0 - up, 1 - down, 2 - left, 3
  - right) \returns boolean (was the move succesful or the field remained
  unchanged)
  */
  bool moveTile(const int position, const int direction);

  /*! Returns a std::vector<int> of size 16, index is a position, value is the
   * number of a tile located at the position. */
  std::vector<int> getTiles() const;
};
