#ifndef COMMANDS_H
#define COMMANDS_H

typedef int Command;

const Command NO_COMMAND = -1;
const Command CONNECT = 0;
const Command DISCONNECT = 1;


// Connexion 100 -> 149

const Command LOGIN = 100;
const Command NICK_USED = 105;
const Command ROOM_LIST = 110;
const Command ROOM_CREATE = 111;
const Command ROOM_JOIN = 112;

// Room 150 -> 199
const Command PLAYER_JOINED = 150;
const Command PLAYER_LEFT = 151;

const Command PLAYER_MESSAGE = 155;

const Command GAME_START = 160;

// Play 200 -> 299
const Command POKER_BET = 200;
const Command POKER_CHECK = 201;
const Command POKER_ALL_IN = 202;
const Command POKER_FOLD = 203;

const Command POKER_NEW_TOTAL_CASH = 209;

const Command POKER_ROUND_ONE = 210;
const Command POKER_ROUND_TWO = 211;
const Command POKER_ROUND_THREE = 212;

const Command POKER_CURRENT_PLAYER = 215;
const Command POKER_BUTTON = 216;
const Command POKER_SMALL_BLIND = 217;
const Command POKER_BIG_BLIND = 218;


const Command POKER_GIVE_CARD = 240;
const Command POKER_SHOW_CARD_PLAYER = 245;
const Command POKER_SHOW_CARD_TABLE = 250;

#endif // COMMANDS_H
