# Download latest .dll [here](https://github.com/noddegazi/activity-gmod-x64/releases/tag/v1.0.0)

# activity-gmod-x64
GMod module that allows to perform discord webhook things via Lua
> [!WARNING]
> Chromium Framework x86-64 necessary

## To send message via webhook you need to use this function

```lua
MessagePush(string webhook_name, string msg, string webhook_url)
```

## Here`s an example

```lua
function CTrack(name, ip)
    MessagePush("Tracker", name .. " has joined the game", url:GetString())
end

hook.Add("PlayerConnect", "SendConnect", CTrack)
```
> [!TIP]
> Webhook URL can be saved as string in local function, or in ConVaR

```lua
local url = "PLACE_URL_HERE"

-- Or you can use ConVar as mentioned

url = CreateConVar("activity_url", "", {FCVAR_ARCHIVE, FCVAR_NOTIFY, FCVAR_REPLICATED, FCVAR_CHEAT}, "Place webhook URL here")
```
