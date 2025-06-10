string printSequence(string S) {
    // code here.
    vector<string> keypad(26);
    // Mapping for mobile keypad
    keypad[0] = "2";     // A
    keypad[1] = "22";    // B
    keypad[2] = "222";   // C
    keypad[3] = "3";     // D
    keypad[4] = "33";    // E
    keypad[5] = "333";   // F
    keypad[6] = "4";     // G
    keypad[7] = "44";    // H
    keypad[8] = "444";   // I
    keypad[9] = "5";     // J
    keypad[10] = "55";   // K
    keypad[11] = "555";  // L
    keypad[12] = "6";    // M
    keypad[13] = "66";   // N
    keypad[14] = "666";  // O
    keypad[15] = "7";    // P
    keypad[16] = "77";   // Q
    keypad[17] = "777";  // R
    keypad[18] = "7777"; // S
    keypad[19] = "8";    // T
    keypad[20] = "88";   // U
    keypad[21] = "888";  // V
    keypad[22] = "9";    // W
    keypad[23] = "99";   // X
    keypad[24] = "999";  // Y
    keypad[25] = "9999"; // Z
    string result = "";
    for (char ch : S) {
        if (ch == ' ') {
            result += "0";
        } else {
            result += keypad[ch - 'A'];
        }
    }
    return result;
}