#ifndef COMMANDS_H
#define COMMANDS_H

typedef int Command;

const Command NO_COMMAND = -1;
const Command CONNECT = 0;


// Connexion 100 -> 149

const Command LOGIN = 100;
const Command NICK_USED = 105;

// Room 150 -> 199
const Command PLAYER_JOINED = 150;
const Command PLAYER_LEFT = 151;

const Command PLAYER_MESSAGE = 155;

// Play 200 -> 299
const Command POKER_CHECK = 200;
const Command POKER_CALL = 201;
const Command POKER_ALL_IN = 202;
const Command POKER_FOLD = 205;
const Command POKER_RAISE = 206;

const Command POKER_NEW_TOTAL_CASH = 209;

const Command POKER_ROUND_ONE = 210;
const Command POKER_ROUND_TWO = 211;
const Command POKER_ROUND_THREE = 212;

const Command POKER_NEXT_PLAYER = 215;
const Command POKER_BUTTON = 216;
const Command POKER_SMALL_BLIND = 217;
const Command POKER_BIG_BLIND = 217;


const Command POKER_GIVE_CARD = 240;
const Command POKER_SHOW_CARD_PLAYER = 245;
const Command POKER_SHOW_CARD_TABLE = 250;

/*Exemple de projet précédent :
// UserManager 1000-> 1499
const Command USER_LOGIN = 1000;
const Command USER_SUBSCRIBE = 1001;
const Command USER_LOGOUT = 1002;
const Command USER_CHANGE_PASSWORD = 1003;
const Command USER_CHANGE_EMAIL = 1004;
const Command USER_CHANGE_BACCOUNT = 1005;
const Command USER_BANK_TO_CASINO = 1006;
const Command USER_CASINO_TO_BANK = 1007;
const Command USER_QUIT = 1008;
const Command USER_GET_PUB_IMAGE = 1009; */

#endif // COMMANDS_H
