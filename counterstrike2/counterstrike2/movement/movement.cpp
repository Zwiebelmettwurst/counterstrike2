#include "movement.hpp"

#include "../source2-sdk/sdk.hpp"

void movement::run_bhop(c_user_cmd* cmd)
{

    if (!interfaces::engine->is_connected() || !interfaces::engine->is_in_game())
    {
        return;
    }

    if (!sdk::local_player || !sdk::local_player->is_alive())
    {
        return;
    }

    if (sdk::local_player->move_type() == movetype_t::movetype_ladder || sdk::local_player->move_type() == movetype_t::movetype_noclip)
    {
        return;
    }

    if (!(sdk::local_player->flags() & fl_onground))
    {
        cmd->buttons &= ~in_jump;
    }
}