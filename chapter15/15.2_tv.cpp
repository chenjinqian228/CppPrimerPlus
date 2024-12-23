// tv.cpp -- Tv类的方法实现（Remote类的方法为内联）
#include <iostream>
#include "15.1_tv.h"

// 音量增加方法
bool Tv::volup()
{
    if (volume < MaxVal)  // 如果当前音量小于最大值
    {
        volume++;         // 音量加1
        return true;      // 返回成功
    }
    else
        return false;     // 否则返回失败
}

// 音量减小方法 
bool Tv::voldown()
{
    if (volume > MinVal)  // 如果当前音量大于最小值
    {
        volume--;         // 音量减1
        return true;      // 返回成功
    }
    else
        return false;     // 否则返回失败
}

// 频道增加方法
void Tv::chanup()
{
    if (channel < maxchannel)  // 如果当前频道小于最大频道
        channel++;             // 频道加1
    else
        channel = 1;          // 否则回到第一个频道
}

// 频道减小方法
void Tv::chandown()
{
    if (channel > 1)          // 如果当前频道大于1
        channel--;            // 频道减1
    else
        channel = maxchannel; // 否则跳到最大频道
}

// 显示电视机设置状态
void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "电视机状态：" << (state == Off? "关闭" : "开启") << endl;
    if (state == On)  // 如果电视机开启
    {
        cout << "音量设置 = " << volume << endl;
        cout << "频道设置 = " << channel << endl;
        cout << "模式 = "
             << (mode == Antenna? "天线" : "有线") << endl;
        cout << "输入源 = "
             << (input == TV? "电视" : "DVD") << endl;
    }
}
