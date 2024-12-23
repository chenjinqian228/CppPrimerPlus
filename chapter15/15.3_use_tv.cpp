// use_tv.cpp -- 使用 Tv 和 Remote 类
#include <iostream>
#include "15.1_tv.h"
#include "15.2_tv.cpp"

int main()
{
    using std::cout;

    // 创建一个42寸电视对象 
    Tv s42;
    cout << "42寸电视的初始设置：\n";
    s42.settings();  // 显示初始设置
    s42.onoff();     // 打开电视
    s42.chanup();    // 频道+1
    cout << "\n42寸电视的调整后设置：\n";
    s42.settings();  // 显示调整后的设置

    // 创建遥控器对象
    Remote grey;

    // 使用遥控器调整42寸电视
    grey.set_chan(s42, 10); // 设置频道为10
    grey.volup(s42);        // 音量+1
    grey.volup(s42);        // 音量+1
    cout << "\n使用遥控器后42寸电视的设置：\n";
    s42.settings();         // 显示遥控调整后的设置

    // 创建58寸电视对象,并设置为开机状态
    Tv s58(Tv::On);
    s58.set_mode();         // 切换模式(有线/天线)
    grey.set_chan(s58,28);  // 使用遥控器设置频道为28
    cout << "\n58寸电视的设置：\n";
    s58.settings();         // 显示58寸电视的设置
    // std::cin.get();
    return 0;
}
