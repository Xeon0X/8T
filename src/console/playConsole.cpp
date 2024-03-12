#include "Console.h"
#include <iostream>
#include "../core/Game.h"
#include "../core/Card.h"

int main()
{
    // Console console;
    // console.play();
    std::cout << "Hello World!" << std::endl;
    return 0;
}










// #include "Console.h"

// #include <memory>  // for shared_ptr, allocator, __shared_ptr_access
 
// #include "ftxui/component/captured_mouse.hpp"  // for ftxui
// #include "ftxui/component/component.hpp"  // for Renderer, ResizableSplitBottom, ResizableSplitLeft, ResizableSplitRight, ResizableSplitTop, CatchEvent
// #include "ftxui/component/component_base.hpp"      // for ComponentBase
// #include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
// #include "ftxui/dom/elements.hpp"  // for Element, operator|, text, center, border, text, vbox, window, Element, Elements
// #include "ftxui/component/event.hpp"           // for Event
// #include "ftxui/component/mouse.hpp"  // for Mouse, Mouse::Left, Mouse::Middle, Mouse::None, Mouse::Pressed, Mouse::Released, Mouse::Right, Mouse::WheelDown, Mouse::WheelUp

// using namespace ftxui;

// int main() {
//   auto screen = ScreenInteractive::Fullscreen();
//   int buttonSize = 10;

//   int value = 0;
//   auto action = [&] { value++; buttonSize++;};
//   auto action_renderer =
//       Renderer([&] { return text("count = " + std::to_string(value)); });

//   std::vector<Component> containers;
//   for (int k = 0; k < buttonSize; k++) {
//     std::vector<Component> list_buttons;
//     for (int l = 0; l < buttonSize; l++) {
//       list_buttons.push_back(Button("Ascii " + std::to_string(k) + " " + std::to_string(l), action, ButtonOption::Simple()) | size(WIDTH, EQUAL, 10) |
//          size(HEIGHT, EQUAL, 5) | center);
//     }
//     auto container = Container::Horizontal(list_buttons);
//     containers.push_back(container);
//   }

//   auto buttons = 
//     Container::Vertical({
//           action_renderer,
//           Renderer([] { return separator(); }),
//           Container::Vertical(containers),
//     }) | center | border | center;

//   auto but = Renderer([&] {
//     Elements elements;
//     elements.push_back(text("count = " + std::to_string(value)));
//     elements.push_back(separator());

//     for (int k = 0; k < 5; k++) {
//         Elements list_buttons;
//         for (int l = 0; l < 3; l++) {
//             list_buttons.push_back(text("Ascii " + std::to_string(k) + " " + std::to_string(l)) | size(WIDTH, EQUAL, buttonSize) |
//                 size(HEIGHT, EQUAL, 5) | center);
//         }
//         elements.push_back(hbox(list_buttons));
//     }

//     return vbox(elements) | center | border | center;
// });

//   // ------------------------

//   auto window = but;
//   auto right = Renderer([] { return text("Scores") | center; });
//   auto top = Renderer([] { return text("Scores") | center; });
//   auto bottom = Renderer([] { return text("Scores") | center; });

//   int right_size = 20;
//   int top_size = 5;
//   int bottom_size = 5;
 
//   window = ResizableSplitRight(right, window, &right_size);
//   window = ResizableSplitTop(top, window, &top_size);
//   window = ResizableSplitBottom(bottom, window, &bottom_size);
 
//   auto renderer =
//       Renderer(window, [&] { return window->Render() | border; });
 
//   screen.Loop(renderer);
// }

// #include "ftxui/component/component.hpp"
// #include "ftxui/component/screen_interactive.hpp"
// #include "ftxui/dom/elements.hpp"

// #include "ftxui-grid-container/grid-container.hpp"

// using namespace ftxui;

// int main() {
//   auto screen = ScreenInteractive::TerminalOutput();
//   std::string output;

//   auto style = size(WIDTH, EQUAL, 5);

//   auto f = [&](const std::string& input) { output += input; };

//   auto button0 = Button("0", [&] { f("0"); }) | style;
//   auto button1 = Button("1", [&] { f("1"); }) | style;
//   auto button2 = Button("2", [&] { f("2"); }) | style;
//   auto button3 = Button("3", [&] { f("3"); }) | style;
//   auto button4 = Button("4", [&] { f("4"); }) | style;
//   auto button5 = Button("5", [&] { f("5"); }) | style;
//   auto button6 = Button("6", [&] { f("6"); }) | style;
//   auto button7 = Button("7", [&] { f("7"); }) | style;
//   auto button8 = Button("8", [&] { f("8"); }) | style;
//   auto button9 = Button("9", [&] { f("9"); }) | style;

//   auto backButton = Button("B",
//                            [&] {
//                              if (output.length() != 0) {
//                                output.pop_back();
//                              }
//                            }) |
//                     style;

//   auto resetButton = Button("R", [&] { output = ""; }) | style;

//   auto grid = GridContainer({{button1, button2, button3},
//                              {button4, button5, button6},
//                              {button7, button8, button9},
//                              {resetButton, button0, backButton}});

//   auto renderer = Renderer(grid, [&] {
//     return window(text("keypad") | center,
//                   {
//                       vbox({
//                           text(output) | border,
//                           grid->Render() | center | flex,
//                       }),
//                   }) |
//            size(WIDTH, EQUAL, 30) | center;
//   });

//   screen.Loop(renderer);
// }