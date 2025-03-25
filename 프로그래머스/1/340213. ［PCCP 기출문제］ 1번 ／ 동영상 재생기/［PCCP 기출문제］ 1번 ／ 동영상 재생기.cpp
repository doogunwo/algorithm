#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

// "mm:ss" → 초로 변환
int timeToSeconds(const string& timeStr) {
    int minutes = 0, seconds = 0;
    sscanf(timeStr.c_str(), "%d:%d", &minutes, &seconds);
    return minutes * 60 + seconds;
}

// 초 → "mm:ss" 문자열로 변환
string secondsToTime(int totalSeconds) {
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    ostringstream oss;
    oss << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds;
    return oss.str();
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int videoSeconds = timeToSeconds(video_len);
    int current = timeToSeconds(pos);
    int opStart = timeToSeconds(op_start);
    int opEnd = timeToSeconds(op_end);

    for (const string& cmd : commands) {
        // 오프닝 건너뛰기 먼저 확인
        if (current >= opStart && current <= opEnd) {
            current = opEnd;
        }

        if (cmd == "prev") {
            current = max(0, current - 10);
        } else if (cmd == "next") {
            current = min(videoSeconds, current + 10);
        }
    }

    // 마지막에 한 번 더 오프닝 체크
    if (current >= opStart && current <= opEnd) {
        current = opEnd;
    }

    return secondsToTime(current);
}
