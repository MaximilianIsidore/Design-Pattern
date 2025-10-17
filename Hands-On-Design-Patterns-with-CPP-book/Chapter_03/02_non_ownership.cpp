#include <iostream>
#include <vector>

struct Widget : public std::vector<int> {
    Widget(std::initializer_list<int> l) : std::vector<int>(l) {
        std::cout << "New Widget constructed" << std::endl;
    }
    ~Widget() { std::cout << "Deleting Widget" << std::endl; }
};

class WidgetProcessor {
  public:
  WidgetProcessor(Widget* w) : w_(w) {}
  Widget* get() { return w_; }
  ~WidgetProcessor() { /* DO NOT delete w_! */ }
  private:
  Widget* w_;	// I do not own w_
};

void Transmorgrify(Widget* w) {
    // w can be null, or we would have used a reference
    if (!w) return;
    // Operate on w, change it (non-const pointer!) but do not delete it
    for (auto& x : *w) x *= 2;
}

void print(Widget* w){
    if(!w) return;

    for(auto x : *w) std::cout<<x<<" ";
    std::cout<<"\n";
}

int main() {
    Widget w{{1, 2, 3}};
    print(&w);
    WidgetProcessor wp(&w);
    std::cout << "Transmogrify - w must not be deleted" << std::endl;
    Transmorgrify(wp.get()); // You can work on it but I still own it
    print(&w);
    std::cout << "Transmogrify done" << std::endl;
    std::cout << "w is deleted by the owner" << std::endl;
}
