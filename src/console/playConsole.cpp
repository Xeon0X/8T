#include "Console.h"

#include <memory>  // for shared_ptr, allocator, __shared_ptr_access
 
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Renderer, ResizableSplitBottom, ResizableSplitLeft, ResizableSplitRight, ResizableSplitTop, CatchEvent
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for Element, operator|, text, center, border, text, vbox, window, Element, Elements
#include "ftxui/component/event.hpp"           // for Event
#include "ftxui/component/mouse.hpp"  // for Mouse, Mouse::Left, Mouse::Middle, Mouse::None, Mouse::Pressed, Mouse::Released, Mouse::Right, Mouse::WheelDown, Mouse::WheelUp

using namespace ftxui;

// Input

std::string Stringify(Event event) {
  std::string out;
  for (auto& it : event.input())
    out += " " + std::to_string((unsigned int)it);
 
  out = "(" + out + " ) -> ";
  if (event.is_character()) {
    out += "Event::Character(\"" + event.character() + "\")";
  } else if (event.is_mouse()) {
    out += "mouse";
    switch (event.mouse().button) {
      case Mouse::Left:
        out += "_left";
        break;
      case Mouse::Middle:
        out += "_middle";
        break;
      case Mouse::Right:
        out += "_right";
        break;
      case Mouse::None:
        out += "_none";
        break;
      case Mouse::WheelUp:
        out += "_wheel_up";
        break;
      case Mouse::WheelDown:
        out += "_wheel_down";
        break;
    }
    switch (event.mouse().motion) {
      case Mouse::Pressed:
        out += "_pressed";
        break;
      case Mouse::Released:
        out += "_released";
        break;
      case Mouse::Moved:
        out += "_moved";
        break;
    }
    if (event.mouse().control)
      out += "_control";
    if (event.mouse().shift)
      out += "_shift";
    if (event.mouse().meta)
      out += "_meta";
 
    out += "(" +  //
           std::to_string(event.mouse().x) + "," +
           std::to_string(event.mouse().y) + ")";
  } else if (event == Event::ArrowLeft) {
    out += "Event::ArrowLeft";
  } else if (event == Event::ArrowRight) {
    out += "Event::ArrowRight";
  } else if (event == Event::ArrowUp) {
    out += "Event::ArrowUp";
  } else if (event == Event::ArrowDown) {
    out += "Event::ArrowDown";
  } else if (event == Event::ArrowLeftCtrl) {
    out += "Event::ArrowLeftCtrl";
  } else if (event == Event ::ArrowRightCtrl) {
    out += "Event::ArrowRightCtrl";
  } else if (event == Event::ArrowUpCtrl) {
    out += "Event::ArrowUpCtrl";
  } else if (event == Event::ArrowDownCtrl) {
    out += "Event::ArrowDownCtrl";
  } else if (event == Event::Backspace) {
    out += "Event::Backspace";
  } else if (event == Event::Delete) {
    out += "Event::Delete";
  } else if (event == Event::Escape) {
    out += "Event::Escape";
  } else if (event == Event::Return) {
    out += "Event::Return";
  } else if (event == Event::Tab) {
    out += "Event::Tab";
  } else if (event == Event::TabReverse) {
    out += "Event::TabReverse";
  } else if (event == Event::F1) {
    out += "Event::F1";
  } else if (event == Event::F2) {
    out += "Event::F2";
  } else if (event == Event::F3) {
    out += "Event::F3";
  } else if (event == Event::F4) {
    out += "Event::F4";
  } else if (event == Event::F5) {
    out += "Event::F5";
  } else if (event == Event::F6) {
    out += "Event::F6";
  } else if (event == Event::F7) {
    out += "Event::F7";
  } else if (event == Event::F8) {
    out += "Event::F8";
  } else if (event == Event::F9) {
    out += "Event::F9";
  } else if (event == Event::F10) {
    out += "Event::F10";
  } else if (event == Event::F11) {
    out += "Event::F11";
  } else if (event == Event::F12) {
    out += "Event::F12";
  } else if (event == Event::Home) {
    out += "Event::Home";
  } else if (event == Event::End) {
    out += "Event::End";
  } else if (event == Event::PageUp) {
    out += "Event::PageUp";
  } else if (event == Event::PageDown) {
    out += "Event::PageDown";
  } else if (event == Event::Custom) {
    out += "Custom";
  } else {
    out += "(special)";
  }
  return out;
}

// Grid

Element make_box(int x, int y) {
  std::string title = "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  return text(title) | center | size(WIDTH, EQUAL, 10) |
         size(HEIGHT, EQUAL, 5) | center |
         bgcolor(Color::HSV(x * 255 / 5, 255, y * 255 / 3));
};
 
Element make_grid() {
  std::vector<Elements> rows;
  for (int i = 0; i < 7; i++) {
    std::vector<Element> cols;
    for (int j = 0; j < 4; j++) {
      cols.push_back(make_box(i, j));
    }
    rows.push_back(cols);
  }
 
  return gridbox(rows);
};

// Component make_button(int x, int y) {
//   std::string title = "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
//   return Button(text(title), action, ButtonOption::Animated())
// };

// Element make_buttons_grid() {
//   std::vector<Elements> rows;
//   for (int i = 0; i < 7; i++) {
//     std::vector<Element> cols;
//     for (int j = 0; j < 4; j++) {
//       cols.push_back(make_box(i, j));
//     }
//     rows.push_back(cols);
//   }
 
//   return gridbox(rows);
// };

int main() {
  auto screen = ScreenInteractive::Fullscreen();

  // ------------------------

  std::vector<Event> keys;
 
  auto console = Renderer([&] {
    Elements children;
    for (size_t i = std::max(0, (int)keys.size() - 3); i < keys.size(); ++i)
      children.push_back(text(Stringify(keys[i])));
    return window(text("keys"), vbox(std::move(children)));
  });
 
  console |= CatchEvent([&](Event event) {
    keys.push_back(event);
    return true;
  });

  // ------------------------

  int value = 0;
  auto action = [&] { value++; };
  auto action_renderer =
      Renderer([&] { return text("count = " + std::to_string(value)); });

  std::vector<Component> containers;
  for (int k = 0; k < 10; k++) {
    std::vector<Component> list_buttons;
    for (int l = 0; l < 10; l++) {
      list_buttons.push_back(Button("Ascii " + std::to_string(k) + " " + std::to_string(l), action, ButtonOption::Animated()));
    }
    auto container = Container::Horizontal(list_buttons);
    containers.push_back(container);
  }

  auto buttons = 
      Container::Vertical({
          action_renderer,
          Renderer([] { return separator(); }),
          Container::Vertical(containers),
      }) |
      border;

  // ------------------------

  float focus_x = 0.5f;
  float focus_y = 0.5f;
 
  auto slider_x = Slider("x", &focus_x, 0.f, 1.f, 0.01f);
  auto slider_y = Slider("y", &focus_y, 0.f, 1.f, 0.01f);
    
  auto grid = Renderer(
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
               center;
      });

  auto window = buttons;
  auto right = Renderer([] { return text("Scores") | center; });
  auto top = console;
  auto bottom = grid;

  int right_size = 20;
  int top_size = 5;
  int bottom_size = 5;
 
  window = ResizableSplitRight(right, window, &right_size);
  window = ResizableSplitTop(top, window, &top_size);
  window = ResizableSplitBottom(bottom, window, &bottom_size);
 
  auto renderer =
      Renderer(window, [&] { return window->Render() | border; });
 
  screen.Loop(renderer);
}