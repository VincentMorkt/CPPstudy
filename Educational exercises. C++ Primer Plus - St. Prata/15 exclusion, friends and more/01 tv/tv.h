// 1 . Измените классы Tv и Remote, как описано ниже.

// а. Сделайте их взаимными друзьями.
// б. Добавьте в класс Remote переменную-член, описывающую режим пульта дистанционного управления - нормальный или интерактивный.
// в. Добавьте метод Remote, который отображает режим.
// г. Добавьте в класс Tv метод для переключения нового члена Remote. Этот метод должен работать, только если телевизор включен.

// Напишите небольшую программу для тестирования новых возможностей.

// tvfm.h -- Tv and Remote classes using a friend member
#ifndef TVFM_H_
#define TVFM_H_
#include <iostream>
class Remote;

class Tv
{
public:
    friend class Remote;
    enum State
    {
        Off,
        On
    };
    enum
    {
        MinVal,
        MaxVal = 20
    };
    enum
    {
        Antenna,
        Cable
    };
    enum
    {
        TV,
        DVD
    };

    Tv(int s = Off, int mc = 125) : state(s), volume(5),
                                    maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() { state = (state == On) ? Off : On; }
    bool ison() const { return state == On; }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
    void set_input() { input = (input == TV) ? DVD : TV; }
    void settings() const;      // show all settings
    bool set_remote(Remote &r); //!

private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
};

class Remote
{
public:
    friend class Tv;
    enum State
    {
        Off,
        On
    };
    enum
    {
        MinVal,
        MaxVal = 20
    };
    enum
    {
        Antenna,
        Cable
    };
    enum
    {
        TV,
        DVD
    };
    enum
    {
        Normal,
        Ineractive
    };

private:
    int mode;
    int RemoteState; //!

public:
    Remote(int m = TV) : mode(m), RemoteState(Normal) {}
    bool volup(Tv &t) { return t.volup(); }
    bool voldown(Tv &t) { return t.voldown(); }
    void onoff(Tv &t) { t.onoff(); }
    void chanup(Tv &t) { t.chanup(); }
    void chandown(Tv &t) { t.chandown(); }
    void set_mode(Tv &t) { t.set_mode(); }
    void set_input(Tv &t) { t.set_input(); }
    void set_chan(Tv &t, int c) { t.channel = c; }
    void show_state() const; //!
};

void Remote::show_state() const //!
{
    if (RemoteState == Normal)
        std::cout << "remote state: normal\n";
    else
        std::cout << "remote state: ineractive\n";
}

bool Tv::set_remote(Remote &r) //!
{
    if (state == On)
    {
        r.RemoteState = (r.RemoteState == Remote::Normal) ? Remote::Ineractive : Remote::Normal;
        return true;
    }
    return false;
}

// tv.cpp -- methods for the Tv class (Remote methods are inline)
bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off ? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
             << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "Input = "
             << (input == TV ? "TV" : "DVD") << endl;
    }
}
#endif