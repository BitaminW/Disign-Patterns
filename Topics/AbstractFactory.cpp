#include <bits/stdc++.h>

using namespace std;

class Button;
class CheckBox;
class MacButton;
class WindowButton;
class MacCheckBox;
class WindowCheckBox;

// 버튼 인터페이스
class Button{
public:
    // 버튼 인터페이스는 버튼을 그려주는 함수를 구현해야함
    virtual void Paint() const = 0;

    virtual ~Button() { }
};


class WindowButton : public Button{
public:
    
    // Button 인터페이스의 필수 기능 윈도우로 구현
    void Paint() const override{
        cout << "window Button render." << "\n";
    }
};


class MacButton : public Button{
public:
    // Button 인터페이스의 필수 기능 맥으로 구현
    void Paint() const override{
        cout << "Mac Button render." << "\n";
    }
};

// 체크박스 인터페이스
class CheckBox{
public:
    virtual void Paint() const = 0;
    virtual ~CheckBox() { }
};

class WindowCheckBox : public CheckBox{
public:
    void Paint() const override{
        cout << "WindowCheckBox render" << "\n";
    }
};

class MacCheckBox : public CheckBox{
public:
    void Paint() const override{
        cout << "MacCheckBox render" << "\n";
    }
};

// 팩토리들의 공통 메소드를 가지는 인터페이스
class GUIFactory{
public:
    virtual Button* createButton() const = 0;
    virtual CheckBox* createCheckBox() const = 0;
    
    virtual ~GUIFactory() {}
};

// GUI Factory를 상속받아 버튼과 체크박스를 반환하는 메소드를 구현
class WinFactory : public GUIFactory{
public:
    Button* createButton() const override{
        return new WindowButton();
    }

    CheckBox* createCheckBox() const override{
        return new WindowCheckBox();
    }
};

class MacFactory : public GUIFactory{
public:
    Button* createButton() const override{
        return new MacButton();
    }

    CheckBox* createCheckBox() const override{
        return new MacCheckBox();
    }
};

// 팩토리를 사용하는 소비자
class Application{
private:
    Button* button;
    CheckBox* checkBox;

public:
    Application(GUIFactory& factory){
        button = factory.createButton();
        checkBox = factory.createCheckBox();
    }

    void paint() const {
        button->Paint();
        checkBox->Paint();
    }

    ~Application() {delete button; delete checkBox;}
};

int main(){

    WinFactory winFactory;
    Application* app = new Application(winFactory);

    app->paint();
    delete app;

    return 0;
}
