#include "discord.hpp"

Discord discordrpc;

void Discord::Init()
{
	DiscordEventHandlers Handle;
	memset(&Handle, 0, sizeof(Handle));
	Discord_Initialize("appid", &Handle, 1, NULL);
}

void Discord::Update()
{
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = TextFormat("Killed owls: %i", points);
	discordPresence.details = "Shooting Owls";
	discordPresence.startTimestamp = 1507665886;
	discordPresence.endTimestamp = 1507665886;
	discordPresence.largeImageText = "OwlKilla";
	discordPresence.largeImageKey = "_4jrfu";
	discordPresence.smallImageText = "Goofy Owl";
	discordPresence.smallImageKey = "goofyowl";
	Discord_UpdatePresence(&discordPresence);
}
