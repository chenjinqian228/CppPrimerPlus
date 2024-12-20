// hangman.cpp -- some string methods
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::string;
const int NUM = 26;
const string wordlist[NUM] = {"apiary", "beetle", "cereal",
    "danger", "ensign", "florid", "garage", "health", "insult",
    "jackal", "keeper", "loaner", "manage", "nonce", "onset",
    "plaid", "quilt", "remote", "stolid", "train", "useful",
    "valid", "whence", "xenon", "yearn", "zippy"};

int main()
{
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;
    
    std::srand(std::time(0));
    char play;
    cout << "你要玩文字游戏吗? <y/n> ";
    cin >> play;
    play = tolower(play);
    while (play == 'y')
    {
        string target = wordlist[std::rand() % NUM];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "猜猜我的秘密单词。它有 " << length
            << " 个字母，你每次只能\n"
            << "猜一个字母。你有 " << guesses
            << " 次猜错的机会。\n";
        cout << "你的单词: " << attempt << endl;
        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "猜一个字母: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos
                || attempt.find(letter) != string::npos)
            {
                cout << "你已经猜过这个字母了。请重试。\n";
                continue;
            }
            int loc = target.find(letter);
            if (loc == string::npos)
            {
                cout << "哦，猜错了!\n";
                --guesses;
                badchars += letter; // 添加到字符串
            }
            else
            {
                cout << "猜对了!\n";
                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
            cout << "你的单词: " << attempt << endl;
            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "错误的选择: " << badchars << endl;
                cout << "还剩 " << guesses << " 次猜错机会\n";
            }
        }
        if (guesses > 0)
            cout << "答对了!\n";
        else
            cout << "抱歉，这个单词是 " << target << "。\n";

        cout << "还要再玩一次吗? <y/n> ";
        cin >> play;
        play = tolower(play);
    }

    cout << "再见\n";

    return 0; 
}
