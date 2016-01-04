#include "card.h"

Card::Card() {}

Card::Card(Rank rank, Suit suit) :
    m_rank(rank),
    m_suit(suit)
{}

Card::Rank Card::getRank() const {
    return m_rank;
}

Card::Suit Card::getSuit() const {
    return m_suit;
}

std::string Card::toString() const {
    std::string value;
    switch(this->getSuit())
    {
        case Card::CLUBS: value = "CLUBS"; break;
        case Card::DIAMONDS: value = "DIAMONDS"; break;
        case Card::HEARTS: value = "HEARTS"; break;
        case Card::SPADES: value = "SPADES"; break;
        default : value = "ERR"; break;
    }
    value += "/";
    switch(this->getRank())
    {
        case Card::ACE: value +=  "ACE"; break;
        case Card::TWO: value +=  "TWO"; break;
        case Card::THREE: value +=  "THREE"; break;
        case Card::FOUR: value +=  "FOUR"; break;
        case Card::FIVE: value +=  "FIVE"; break;
        case Card::SIX: value += "SIX"; break;
        case Card::SEVEN: value += "SEVEN"; break;
        case Card::HEIGHT: value += "EIGHT"; break;
        case Card::NINE: value += "NINE"; break;
        case Card::TEN: value += "TEN"; break;
        case Card::JACK: value += "JACK"; break;
        case Card::QUEEN: value += "QUEEN"; break;
        case Card::KING: value += "KING"; break;
        default : value += "ERR"; break;
    }
    return value;
}

std::ostream& operator<<(std::ostream& os, Card card) {
    os << card.toString();
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

