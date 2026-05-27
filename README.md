# activity-gmod-x64
GMod module that allows to perform discord webhook things via Lua
> [!WARNING]
> Chromium x86-64 is necessary

To send message via hook you need to use this func

```lua
MessagePush(string webhook_name, string msg, string webhook_url)
```

Here`s an example

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

url = CreateConVar("activity_url", "", {FCVAR_ARCHIVE, FCVAR_NOTIFY, FCVAR_REPLICATED, FCVAR_CHEAT}, "Place webhook URL here")
```
