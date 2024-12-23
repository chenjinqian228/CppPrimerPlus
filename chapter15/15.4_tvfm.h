// tvfm.h -- 使用友元成员的电视和遥控器类
#ifndef TVFM_H_
#define TVFM_H_

class Tv;                       // 前向声明

// 遥控器类
class Remote
{
public:
    enum State{Off, On};        // 关闭、开启状态枚举
    enum {MinVal,MaxVal = 20};  // 音量最小值、最大值
    enum {Antenna, Cable};      // 天线、有线模式枚举
    enum {TV, DVD};            // 电视、DVD设备枚举
private:
    int mode;                   // 当前控制模式(TV或DVD)
public:
    Remote(int m = TV) : mode(m) {}  // 构造函数,默认为TV模式
    bool volup(Tv & t);        // 增加音量
    bool voldown(Tv & t);      // 减小音量 
    void onoff(Tv & t);        // 开关电视
    void chanup(Tv & t);       // 频道增加
    void chandown(Tv & t);     // 频道减少
    void set_mode(Tv & t);     // 设置天线/有线模式
    void set_input(Tv & t);    // 设置输入源(TV/DVD)
    void set_chan(Tv & t, int c); // 设置指定频道
};

// 电视机类
class Tv
{
public:
    friend void Remote::set_chan(Tv & t, int c);  // 声明Remote的set_chan为友元函数
    enum State{Off, On};         // 关闭、开启状态枚举
    enum {MinVal,MaxVal = 20};   // 音量最小值、最大值
    enum {Antenna, Cable};       // 天线、有线模式枚举  
    enum {TV, DVD};             // 电视、DVD设备枚举
    
    // 构造函数,默认为关闭状态,最大频道125
    Tv(int s = Off, int mc = 125) : state(s), volume(5),
        maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {state = (state == On) ? Off : On;}  // 切换开关状态
    bool ison() const {return state == On;}  // 判断是否开启
    bool volup();               // 增加音量
    bool voldown();             // 减小音量
    void chanup();              // 频道增加
    void chandown();            // 频道减少
    void set_mode() {mode = (mode == Antenna) ? Cable : Antenna;}  // 切换天线/有线模式
    void set_input() {input = (input == TV) ? DVD : TV;}  // 切换输入源
    void settings() const;      // 显示当前所有设置
private:
    int state;                  // 开关状态
    int volume;                 // 音量大小
    int maxchannel;            // 最大频道数
    int channel;               // 当前频道
    int mode;                  // 天线/有线模式
    int input;                 // TV/DVD输入源
};

// Remote类内联函数实现
inline bool Remote::volup(Tv & t) { return t.volup();}
inline bool Remote::voldown(Tv & t) { return t.voldown();}
inline void Remote::onoff(Tv & t) { t.onoff(); }
inline void Remote::chanup(Tv & t) {t.chanup();}
inline void Remote::chandown(Tv & t) {t.chandown();}
inline void Remote::set_mode(Tv & t) {t.set_mode();}
inline void Remote::set_input(Tv & t) {t.set_input();}
inline void Remote::set_chan(Tv & t, int c) {t.channel = c;}

#endif
