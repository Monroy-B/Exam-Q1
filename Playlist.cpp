#include "Playlist.hpp"

Playlist::Playlist() : numSongs_(0), totalMinutes_(0.0) {}
Playlist::Playlist(int n, double t) : numSongs_(n), totalMinutes_(t) {}

void Playlist::setNumSongs(int n) { numSongs_ = n; }
void Playlist::setTotalMinutes(double t) { totalMinutes_ = t; }

int Playlist::getNumSongs() const { return numSongs_; }
double Playlist::getTotalMinutes() const { return totalMinutes_; }

double Playlist::averageSongLength() const {
    if (numSongs_ == 0) { return 0.0; }
    return totalMinutes_ / numSongs_;
}

Playlist Playlist::operator+(const Playlist& other) {
    return Playlist(numSongs_ + other.numSongs_, totalMinutes_ + other.totalMinutes_);
}