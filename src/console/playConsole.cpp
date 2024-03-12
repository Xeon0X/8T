#include "Console.h"

#include <memory>  // for shared_ptr, allocator, __shared_ptr_access
 
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Renderer, ResizableSplitBottom, ResizableSplitLeft, ResizableSplitRight, ResizableSplitTop
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for Element, operator|, text, center, border
 
using namespace ftxui;
 
Element make_box(int x, int y) {
  std::string title = "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  return text(title) | center | size(WIDTH, EQUAL, 18) |
         size(HEIGHT, EQUAL, 9) | border |
         bgcolor(Color::HSV(x * 255 / 15, 255, y * 255 / 15));
};
 
Element make_grid() {
  std::vector<Elements> rows;
  for (int i = 0; i < 15; i++) {
    std::vector<Element> cols;
    for (int j = 0; j < 15; j++) {
      cols.push_back(make_box(i, j));
    }
    rows.push_back(cols);
  }
 
  return gridbox(rows);
};

int main() {
  auto screen = ScreenInteractive::Fullscreen();
  int value = 0;
  auto action = [&] { value++; };
  auto action_renderer =
      Renderer([&] { return text("count = " + std::to_string(value)); });

  float focus_x = 0.5f;
  float focus_y = 0.5f;
 
  auto slider_x = Slider("x", &focus_x, 0.f, 1.f, 0.01f);
  auto slider_y = Slider("y", &focus_y, 0.f, 1.f, 0.01f);
    
  auto buttons = Renderer(
      Container::Vertical({
          slider_x,
          slider_y,
      }),
      [&] {
        auto title = "focusPositionRelative(" +        //
                     std::to_string(focus_x) + ", " +  //
                     std::to_string(focus_y) + ")";    //
        return vbox({
                   text(title),
                   separator(),
                   slider_x->Render(),
                   slider_y->Render(),
                   separator(),
                   make_grid() | focusPositionRelative(focus_x, focus_y) |
                       frame | flex,
               }) |
               border;
      });

  auto grid = Renderer([] {
  // Generate grid elements dynamically here
  // For example, you can create a vector of rows and columns
  std::vector<std::vector<Element>> grid_elements;
  
  // Populate grid_elements with elements
  
  // Create the grid element using the populated grid_elements
  Element grid_element = vbox({
      hbox({
        text("one") | border,
        text("two") | border | flex,
        text("three") | border | flex,
      }),

      gauge(0.25) | color(Color::Red),
      gauge(0.50) | color(Color::White),
      gauge(0.75) | color(Color::Blue),
    });
  return grid_element | center;
  });
  auto middle = Renderer([] { return text("middle") | center; });
  auto left = Renderer([] { return text("Left") | center; });
  auto right = Renderer([] { return text("right") | center; });
  auto top = Renderer([] { return text("top") | center; });
  auto bottom = Renderer([] { return text("bottom") | center; });
 
  int left_size = 20;
  int right_size = 20;
  int top_size = 10;
  int bottom_size = 10;
 
  auto container = buttons;
  container = ResizableSplitLeft(left, container, &left_size);
  container = ResizableSplitRight(right, container, &right_size);
  container = ResizableSplitTop(top, container, &top_size);
  container = ResizableSplitBottom(bottom, container, &bottom_size);
 
  auto renderer =
      Renderer(container, [&] { return container->Render() | border; });
 
  screen.Loop(renderer);
}