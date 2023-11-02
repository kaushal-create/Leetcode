class Solution {
public:
    map<string, string> encoded, decoded;
    string base = "https://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = base + to_string(size(longUrl) + 1);
        encoded[longUrl] = shortUrl;
        decoded[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decoded[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));