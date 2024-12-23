// tv.h -- 电视机和遥控器类
#ifndef TV_H_
#define TV_H_

class Tv
{
public:
    friend class Remote;   // Remote类可以访问Tv的私有成员
    enum {Off, On};        // 关闭、打开
    enum {MinVal,MaxVal = 20}; // 最小值、最大值=20
    enum {Antenna, Cable}; // 天线、有线
    enum {TV, DVD};       // 电视、DVD

    // 构造函数:初始化电视状态(默认关闭)和最大频道数(默认125)
    // 音量默认为5,当前频道为2,默认为有线模式,默认为TV输入源
    Tv(int s = Off, int mc = 125) : state(s), volume(5),
        maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {state = (state == On)? Off : On;} // 开关电视
    bool ison() const {return state == On;} // 检查电视是否开启
    bool volup();    // 增大音量
    bool voldown();  // 减小音量 
    void chanup();   // 增加频道号
    void chandown(); // 减小频道号
    void set_mode() {mode = (mode == Antenna)? Cable : Antenna;} // 在天线和有线之间切换
    void set_input() {input = (input == TV)? DVD : TV;} // 在TV和DVD之间切换输入源
    void settings() const; // 显示所有当前设置
    
private:
    int state;      // 开关状态(On或Off)
    int volume;     // 音量大小(0-20)
    int maxchannel; // 最大频道数
    int channel;    // 当前频道号
    int mode;       // 接收模式(天线或有线)
    int input;      // 输入源(TV或DVD)
};

class Remote // 遥控器类
{
public:
    Remote(int m = Tv::TV) : mode(m) {} // 构造函数,默认为TV模式
    bool volup(Tv & t) { return t.volup();} // 增大电视音量
    bool voldown(Tv & t) { return t.voldown();} // 减小电视音量
    void onoff(Tv & t) { t.onoff(); } // 开关电视
    void chanup(Tv & t) {t.chanup();} // 增加电视频道
    void chandown(Tv & t) {t.chandown();} // 减小电视频道
    void set_chan(Tv & t, int c) {t.channel = c;} // 设置指定频道
    void set_mode(Tv & t) {t.set_mode();} // 切换接收模式
    void set_input(Tv & t) {t.set_input();} // 切换输入源
private:
    int mode; // 遥控器当前模式
};
#endif
