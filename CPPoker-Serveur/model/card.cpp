#include "card.h"

Card::Card() {}

Card::Card(Rank rank, Suit suit) :
    rank(rank),
    suit(suit)
{}

Card::Rank Card::getRank() const {
    return rank;
}

Card::Suit Card::getSuit() const {
    return suit;
}

std::ostream& operator<<(std::ostream& os, Card card) {
    switch(card.getRank())
    {
        case Card::ACE: os << "ACE"; break;
        case Card::ONE: os << "ONE"; break;
        case Card::TWO: os << "TWO"; break;
        case Card::THREE: os << "THREE"; break;
        case Card::FOUR: os << "FOUR"; break;
        case Card::FIVE: os << "FIVE"; break;
        case Card::SIX: os << "SIX"; break;
        case Card::SEVEN: os << "SEVEN"; break;
        case Card::HEIGHT: os << "HEIGHT"; break;
        case Card::NINE: os << "NINE"; break;
        case Card::TEN: os << "TEN"; break;
        case Card::JACK: os << "JACK"; break;
        case Card::QUEEN: os << "QUEEN"; break;
        case Card::KING: os << "KING"; break;
        default : os << "ERR"; break;
    }
    os << " OF ";
    switch(card.getSuit())
    {
        case Card::CLUBS: os << "CLUBS"; break;
        case Card::DIAMONDS: os << "DIAMONDS"; break;
        case Card::HEARTS: os << "HEARTS"; break;
        case Card::SPADES: os << "SPADES"; break;
        default : os << "ERR"; break;
    }
    return os;
}

bool operator< (Card const &card1, Card const &card2)
{
    return (static_cast<int>(card1.getRank()) < static_cast<int>(card2.getRank()));
}

bool operator== (Card const &card1, Card const &card2)
{
    return (static_cast<int>(card1.getRank()) == static_cast<int>(card2.getRank()));
}

