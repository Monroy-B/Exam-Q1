class Playlist {
private:
    int numSongs_;
    double totalMinutes_;

    Playlist();
    Playlist(int n, double t);

public:
    void setNumSongs(int n);
    void setTotalMinutes(double t);

    int getNumSongs() const;
    double getTotalMinutes() const;

    double averageSongLength() const;

    Playlist operator+(const Playlist& other);
};