#ifndef CONWAY_H_MLRNEO39
#define CONWAY_H_MLRNEO39

#include <vector>
#include <cstddef>
#include <SFML/Graphics/RenderTarget.hpp>

namespace Conway {
using std::vector;
class Board {
  private:
    const size_t width, height;
    vector<bool> current;
    vector<bool> next;

    unsigned count_neighbours(size_t x, size_t y) const;

    bool get_current(size_t x, size_t y) const;
    void set_next(size_t x, size_t y, bool value);

  public:
    Board(size_t width, size_t height);
    void tick(void);
    void render(sf::RenderTarget &target) const;
};
}

#endif /* end of include guard: CONWAY_H_MLRNEO39 */
