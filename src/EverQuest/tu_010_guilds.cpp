// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 10: a hint from compare/tumap.py.
// The guild object (the global at 0x905D38), seen through many partial views (ListOwner_guess,
// LookupTable_guess, GuildTable_guess, GuildManagement_guess, Table_guess...): 1500 guild names, the member
// list, the MOTD and guild-tribute cost, and the guild message handler. Then the chat-server client
// (ChatServerClient_guess, made by CEverQuest), its clock helpers, and std::vector<std::string> pieces.
#include "titanium/eqaddr.h"
#include "titanium/opcodes.h"
#include "titanium/wnd/CLFGuildWnd.h"
#include "titanium/wnd/CGuildTributeMasterWnd.h"

#include "titanium/core_decls.h"
extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);
extern "C" unsigned int __cdecl strlen(const char* value);
void __cdecl Convert_guess(char* destination, const char* source);

struct DataObject_guess {
    int value_00;
    char flag_04;
    unsigned char unknown_05[3];
    int value_08;
    int value_0c;
    char text_10[0x40];
    int value_50;
    int value_54;
    int value_58;
    int value_5c;
    int value_60;
    char buffer_64[0x100];
    char buffer_164[0x100];
    char flag_264;
    unsigned char unknown_265[3];
    int value_268;
    int value_26c;
    char flag_270;
    DataObject_guess* Initialize_guess();
    void Set_guess(const char* text, int value_50, int value_54, int value_58,
                   int value_5c, int value_08, int value_60);
};

// A guild member entry (0x274 bytes, the members of an OP_GuildMemberList): empty, rank -1, offline.
// FUNCTION: TITANIUM 0x0040A6CE
DataObject_guess* DataObject_guess::Initialize_guess() {
    value_00 = 0;
    flag_04 = 0;
    value_08 = 0;
    memset(text_10, 0, 0x40);
    value_5c = -1;
    value_50 = 0;
    value_54 = 0;
    value_58 = 0;
    value_60 = 0;
    memset(buffer_64, 0, 0x100);
    memset(buffer_164, 0, 0x100);
    value_0c = 0;
    flag_264 = 0;
    value_268 = 0;
    value_26c = 0;
    return this;
}

// Fills a member: name, level, banker flags, class, rank, zone and last-on time. A nonzero zone means
// the member is online (flag_04).
// FUNCTION: TITANIUM 0x0040A735
void DataObject_guess::Set_guess(const char* text, int value_50, int value_54, int value_58,
                                 int value_5c, int value_08, int value_60) {
    Convert_guess(text_10, text);
    this->value_50 = value_50;
    this->value_54 = value_54;
    this->value_58 = value_58;
    this->value_5c = value_5c;
    this->value_08 = value_08;
    if (value_08 != 0) {
        flag_04 = 1;
    }
    this->value_60 = value_60;
}

struct Record_guess {
    union {
        unsigned char value;
        char text[0x40];
    };
};

struct RecordTable_guess {
    unsigned char unknown_00[0x4c];
    Record_guess records[0x5dc];
    char IsGuildValid_guess(int index);
    int FindGuildIdByNamePrefix_guess(char* text);
};

// True when guild id `index` (0-1499) has a name.
// FUNCTION: TITANIUM 0x0040A77A
char RecordTable_guess::IsGuildValid_guess(int index) {
    if (index < 0 || index >= 0x5dc) {
        return false;
    }
    return records[index].value != 0;
}

// EXTERNAL: TITANIUM 0x0062202C _strnicmp
int __cdecl _strnicmp(const char* first, const char* second, unsigned int count);

// Guild id for a name, -1 when none or when the name is over 30 characters. Only the query's length is
// compared, so a prefix matches the first guild that starts with it.
// FUNCTION: TITANIUM 0x0040A79B
int RecordTable_guess::FindGuildIdByNamePrefix_guess(char* text) {
    int result = -1;
    if (text == 0) {
        return -1;
    }
    int length = strlen(text);
    if (length > 0x1e) {
        return -1;
    }
    int index = 0;
    do {
        if (records[index].text[0] != 0 &&
            _strnicmp(records[index].text, text, length) == 0) {
            result = index;
            break;
        }
        ++index;
    } while (index < 0x5dc);
    return result;
}

struct RemoveRequest_guess {
    int unknown_00;       // 0x00
    char text_004[0x40];  // 0x04
};

struct CreateRequest_guess {
    unsigned char unknown_00[0x08];
    int value_08;         // 0x08
    int value_0c;         // 0x0c
    int value_10;         // 0x10
    int value_14;         // 0x14
    int value_18;         // 0x18
    char text_1c[0x40];   // 0x1c
};

struct ListNode_guess {
    ListNode_guess* next;            // 0x00
    char flag_04;                    // 0x04
    unsigned char unknown_05[0x0b];  // 0x05
    char text_10[0x40];              // 0x10
    int value_50;                    // 0x50
    unsigned char unknown_54[0x210];
    char flag_264;
    unsigned char unknown_265[0x0b];
    char flag_270;
};

struct Observer_guess {
    // EXTERNAL: TITANIUM 0x0051059A Observer_guess::AddMember_guess
    void AddMember_guess(int* value);
};

#define g_observer_guess EQ_GLOBAL(Observer_guess*, 0x00991AAC)

struct SoundManager_guess {
    // EXTERNAL: TITANIUM 0x00510D2F SoundManager_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x0050F4D2 SoundManager_guess::RemoveMember_guess
    void RemoveMember_guess(ListNode_guess* node);
    // EXTERNAL: TITANIUM 0x0050E6C2 SoundManager_guess::SetPlayerCount_guess
    void SetPlayerCount_guess(int count);
    // EXTERNAL: TITANIUM 0x0050E5B5 SoundManager_guess::SetMOTD_guess
    void SetMOTD_guess(char* first, char* second);
    // EXTERNAL: TITANIUM 0x0050F5CC SoundManager_guess::UpdateMemberRow_guess
    void UpdateMemberRow_guess(int id, int index);
    // EXTERNAL: TITANIUM 0x0050F9D2 SoundManager_guess::UpdateNoteRow_guess
    void UpdateNoteRow_guess(int id, int index);
    // EXTERNAL: TITANIUM 0x0050FB61 SoundManager_guess::UpdateTributeRow_guess
    void UpdateTributeRow_guess(int id, int index);
    // EXTERNAL: TITANIUM 0x0050E7A3 SoundManager_guess::RenameMember_guess
    void RenameMember_guess(int key, char* text);
    // EXTERNAL: TITANIUM 0x005101B6 SoundManager_guess::SortMembers_guess
    void SortMembers_guess(int first_guess, int second_guess);
};

#define g_soundManager_guess EQ_GLOBAL(SoundManager_guess*, 0x00991AAC)


struct TextRequest_guess {
    unsigned char unknown_00[0x44];
    char text_044[0x44];
    char text_088[1];
};

// EXTERNAL: TITANIUM 0x0060ED40 _strcmp
int __cdecl _strcmp(const char* first, const char* second);

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* output, int size, char* first, char* second,
                              int value_4, int value_5, int value_6, int value_7,
                              int value_8, int value_9, int value_10);

// EXTERNAL: TITANIUM 0x0060E450 CopyText_guess
void __cdecl CopyText_guess(void* destination, const void* source);

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// EXTERNAL: TITANIUM 0x0063FF08 ??_7ListOwner_guess@@6B@
struct ListOwner_guess {
    char flag_04; // 0x04
    unsigned char unknown_05[0x3f];
    int count; // 0x44
    ListNode_guess* head; // 0x48
    union {
        unsigned char unknown_04c[0x17700]; // 0x4c
        Record_guess records_04c[0x5dc];
    };
    union {
        unsigned char unknown_1774c[0x200]; // 0x1774c
        char text_1774c[0x200];
    };
    union {
        unsigned char unknown_1794c[0x40]; // 0x1794c
        char text_1794c[0x40];
    };
    int value_1798c;
    int value_17990;
    unsigned char changed_17994; // 0x17994
    unsigned char unknown_17995[0x07];
    int value_1799c;
    int values_179a0[4];
    int value_179b0;
    unsigned char changed_179b4; // 0x179b4
    unsigned char changed_179b5;
    unsigned char changed_179b6;
    ListOwner_guess();
    virtual ~ListOwner_guess() { Clear_guess(); }
    void Add_guess(int* value);
    void AddFromRequest_guess(CreateRequest_guess* request, int unused_guess);
    void Remove_guess(RemoveRequest_guess* request, int unused_guess);
    void Clear_guess();
    void ClearRecord_guess(int* index);
    void Initialize_guess(char clearBuffer);
    void Recalculate_guess();
    int GetValue_guess();
    void UpdateFromRequest_guess(TextRequest_guess* request);
    ListOwner_guess* Delete_guess(unsigned int flags);
    void LoadGuildMemberList_guess(const unsigned char* stream);
};

// OP_GuildMOTD (EQEmu GuildMOTD_Struct: setter's name at +0x44, text at +0x88). A new, non-empty MOTD is
// printed with string 468 ("GUILD MOTD: %1 - %2"), then stored at +0x1774C and its setter at +0x1794C.
// FUNCTION: TITANIUM 0x0040A7FD
void ListOwner_guess::UpdateFromRequest_guess(TextRequest_guess* request) {
    char buffer[0x400];
    SoundManager_guess* manager = g_soundManager_guess;
    if (manager != 0) {
        manager->SetMOTD_guess(request->text_088, request->text_044);
    }
    char* text = request->text_088;
    if (_strcmp(text_1774c, text) != 0 && text[0] != 0) {
        FormatText_guess(buffer, 0x1d4, request->text_044, text,
                         0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer, 0xf, 1);
    }
    CopyText_guess(text_1774c, text);
    CopyText_guess(text_1794c, request->text_044);
}

// Pushes a member at the head of the list, marks the window and tribute totals stale and tells the
// guild management window (0x991AAC). A first member keeps the zeroed next pointer Initialize_guess wrote.
// FUNCTION: TITANIUM 0x0040A8B5
// @early-stop: unknown, diff ndiff=6
void ListOwner_guess::Add_guess(int* value) {
    if (head != 0) {
        *value = (int)head;
    }
    ++count;
    head = (ListNode_guess*)value;
    changed_17994 = 1;
    changed_179b4 = 1;
    if (g_observer_guess != 0) {
        g_observer_guess->AddMember_guess(value);
    }
}

// Frees every member entry.
// FUNCTION: TITANIUM 0x0040A8E9
void ListOwner_guess::Clear_guess() {
    ListNode_guess* node = head;
    while (node != 0) {
        ListNode_guess* current = node;
        node = node->next;
        free(current);
    }
    count = 0;
    head = 0;
    changed_17994 = 1;
    changed_179b4 = 1;
}

// OP_GuildMemberAdd: level +0x08, class +0x0C, rank +0x10, zone +0x14, last-on +0x18, name +0x1C
// (banker flags start at 0). No check that the allocation worked.
// FUNCTION: TITANIUM 0x0040A918
void ListOwner_guess::AddFromRequest_guess(CreateRequest_guess* request, int unused_guess) {
    DataObject_guess* data;
    DataObject_guess* memory = (DataObject_guess*)operator new(0x274);
    if (memory != 0) {
        data = memory->Initialize_guess();
    } else {
        data = 0;
    }
    data->Set_guess(request->text_1c, request->value_08, 0, request->value_0c,
                    request->value_10, request->value_14, request->value_18);
    Add_guess((int*)data);
    if (g_soundManager_guess != 0) {
        g_soundManager_guess->SetPlayerCount_guess(count);
    }
}

struct SelectedInner_guess {
    int unknown_00;
    int vbaseOffset_0004_guess;
};

struct SelectedIndex_guess {
    unsigned char unknown_000[8];
    SelectedInner_guess* vbtable_0008_guess;
    unsigned char unknown_00c[0xe00];
    int value_e0c;
    unsigned char state_e10;
};

#define g_selectedIndex_guess EQ_GLOBAL(SelectedIndex_guess*, 0x00905D00)

struct RequestMessage_guess {
    int unknown_000;
    char text_004[0x40];
    char text_044[0x40];
    unsigned int flags_084;
};

struct RequestBuffers_guess {
    char format_000[0x200];
    RequestMessage_guess message_200;
};

struct RequestOwner_guess {
    void SendGuildDemote_guess(DataObject_guess* data);
    void SendGuildBankerFlags_guess(DataObject_guess* data, unsigned int mask, char set);
};

// OP_GuildDeleteGuild: forgets guild `*index`'s name. When it is the player's guild (profile +0xE0C),
// the MOTD and the member list go too.
// FUNCTION: TITANIUM 0x0040A977
void ListOwner_guess::ClearRecord_guess(int* index) {
    int value = *index;
    if (value < 0 || value >= 0x5dc) {
        return;
    }
    memset(records_04c[value].text, 0, 0x40);
    if (value == g_selectedIndex_guess->value_e0c) {
        memset(unknown_1774c, 0, 0x200);
        memset(unknown_1794c, 0, 0x40);
        if (g_soundManager_guess != 0) {
            g_soundManager_guess->Refresh_guess();
        }
        Clear_guess();
    }
}

// Empties the member list, MOTD and both guild-tribute slots (id -1, tier 0); `clearBuffer` also wipes the
// 1500 guild names.
// FUNCTION: TITANIUM 0x0040ABBF
void ListOwner_guess::Initialize_guess(char clearBuffer) {
    Clear_guess();
    head = 0;
    count = 0;
    flag_04 = 0;
    if (clearBuffer != 0) {
        memset(unknown_04c, 0, 0x17700);
    }
    memset(unknown_1774c, 0, 0x200);
    memset(unknown_1794c, 0, 0x40);
    value_1798c = 0;
    value_1799c = 0;
    int* entry = &values_179a0[1];
    int i = 2;
    do {
        entry[-1] = -1;
        *entry = 0;
        entry += 2;
        --i;
    } while (i != 0);
    value_17990 = 0;
    changed_179b5 = 0;
    changed_179b6 = 0;
    changed_17994 = 1;
    changed_179b4 = 1;
}

struct AudioState_guess {
    void RefreshGuildMember_guess(int id);
};

// Redraws one member (`id` is the entry) in the guild management window's three lists.
// FUNCTION: TITANIUM 0x0040A9F1
void AudioState_guess::RefreshGuildMember_guess(int id) {
    if (g_soundManager_guess != 0) {
        g_soundManager_guess->UpdateMemberRow_guess(id, -1);
        g_soundManager_guess->UpdateNoteRow_guess(id, -1);
        g_soundManager_guess->UpdateTributeRow_guess(id, -1);
    }
}

struct LookupNode_guess {
    LookupNode_guess* next;          // 0x00
    unsigned char unknown_04[0x0c];  // 0x04
    int value;                       // 0x10
    unsigned char unknown_14[0x3c];  // 0x14
    int level_0050_guess;                   // 0x50
    int value_054;                   // 0x54
    unsigned char unknown_058[0x04]; // 0x58
    int value_05c;                   // 0x5c
    unsigned char unknown_060[0x04]; // 0x60
    char text_064[0x100];            // 0x64
};

struct Request_guess {
    unsigned char unknown_00[0x04];
    int key_004;                     // 0x04
    unsigned char unknown_08[0x3c];
    union {
        int level_0044_guess;               // 0x44
        char text_044[0x100];        // 0x44
    };
};

struct UpdateData_guess {
    unsigned char unknown_00[0x08];
    int value_008;                   // 0x08
    char text_00c[0x40];             // 0x0c
    int value_04c;                   // 0x4c
};

struct LookupTable_guess {
    unsigned char unknown_00[0x48];
    LookupNode_guess* first;         // 0x48
    unsigned char unknown_4c[0x17948];
    unsigned char flag_17994;        // 0x17994
    unsigned char unknown_17995[0x1f];
    unsigned char flag_179b4;        // 0x179b4
    LookupNode_guess* Find_guess(int value);
    void SetGuildMemberLevel_guess(Request_guess* request);
    void RenameGuildMember_guess(Request_guess* request);
    void ConvertRequest_guess(Request_guess* request);
    void UpdateRequest_guess(UpdateData_guess* request);
};

struct LookupOffset_guess {
    int unknown_00;
    int vbaseOffset_0004_guess;                  // 0x04
};

struct LookupGlobals_guess {
    unsigned char unknown_00[0x08];
    LookupOffset_guess* offset_008;  // 0x08
    unsigned char unknown_00c[0xe00];
    int value_e0c;                   // 0xe0c
    unsigned char unknown_e10[0x04];
    int value_e14;                   // 0xe14
};

#define g_lookupGlobals_guess EQ_GLOBAL(LookupGlobals_guess*, 0x00905D00)

// EXTERNAL: TITANIUM 0x00574950 CompareValue_guess
int __cdecl CompareValue_guess(int value, const void* stored);

// Member entry by name (`value` points at the name), or 0.
// FUNCTION: TITANIUM 0x0040AA28
LookupNode_guess* LookupTable_guess::Find_guess(int value) {
    LookupNode_guess* node = first;
    while (node != 0) {
        if (CompareValue_guess(value, &node->value) == 0) {
            return node;
        }
        node = node->next;
    }
    return 0;
}

struct StatRecord_guess {
    unsigned char unknown_00[0x10];
    int thresholds_10[10];
    int increments_38[10];
};

struct StatLookup_guess {
    // EXTERNAL: TITANIUM 0x00434B0A StatLookup_guess::Find_guess
    StatRecord_guess* Find_guess(int key);
};

#define g_statLookup_guess EQ_GLOBAL(StatLookup_guess, 0x00850350)

// Guild tribute cost: each of the two active guild tributes (id, tier) adds its tier cost to every level
// from the tier's minimum level up (0-99), then the cost at each member's level is summed over members
// who are online with tribute on (+0x264, +0x270). The table at 0x850350 is the tribute list.
// FUNCTION: TITANIUM 0x0040AA51
void ListOwner_guess::Recalculate_guess() {
    int totals[100];
    int remaining;
    value_179b0 = 0;
    memset(totals, 0, sizeof(totals));
    int* entry = &values_179a0[1];
    remaining = 2;
    do {
        int key = entry[-1];
        if (key != -1) {
            StatRecord_guess* record = g_statLookup_guess.Find_guess(key);
            if (record != 0) {
                int index = *entry;
                int threshold = record->thresholds_10[index];
                if (threshold < 100) {
                    do {
                        totals[threshold] += record->increments_38[index];
                        ++threshold;
                    } while (threshold < 100);
                }
            }
        }
        entry += 2;
        --remaining;
    } while (remaining != 0);
    ListNode_guess* node = head;
    while (node != 0) {
        if (node->flag_264 != 0 && node->flag_04 != 0 && node->flag_270 != 0) {
            value_179b0 += totals[node->value_50];
        }
        node = node->next;
    }
    changed_179b4 = 0;
}

struct Packet_guess {
    int type_00;         // 0x00
    int value_04;        // 0x04
    char text_08[0x48];  // 0x08
};

struct PacketSource_guess {
    unsigned char unknown_00[0x288];
    int value_288;       // 0x288
};

#define g_packetSource_guess EQ_GLOBAL(PacketSource_guess*, 0x00905CE4)
#define g_packetTarget_guess EQ_ARRAY(int, 0x00905CA0)

// OP_GuildOptInOut (0x50 bytes): the player's guild id (spawn +0x288), `value` and the member `text`;
// the guild management and tribute benefit windows use it for guild tribute opt-in/out.
// FUNCTION: TITANIUM 0x0040AB34
void __stdcall SendPacket_guess(const char* text, int value) {
    Packet_guess packet;
    packet.type_00 = g_packetSource_guess->value_288;
    Convert_guess(packet.text_08, text);
    packet.value_04 = value;
    EQSendMessage(g_packetTarget_guess, OP_GuildOptInOut, &packet, 0x50, 1);
}

// EXTERNAL: TITANIUM 0x00576E80 FUN_00576e80_guess
int __cdecl FUN_00576e80_guess();

struct GuildMessage_guess {
    int id_000;           // 0x00
    char text_004[0x40];  // 0x04
    char text_044[0x40];  // 0x44
    char text_084[0x100]; // 0x84
};

struct GuildTable_guess {
    unsigned char unknown_000[0x4c];
    char names_04c[0x5dc][0x40];        // 0x4c
    unsigned char unknown_1774c[0x240]; // 0x1774c
    int lastTick_1798c;                 // 0x1798c
    char* GetName_guess(int index);
    void SendGuildPublicNote_guess(const char* first, const char* second);
};

// Name of guild id `index`. An id with no name yet is reported as an unknown guild and, at most once per
// 2 clock units (0x576E80), asks the server with message 0x6D5D and the player's name (probably for the
// guild list again).
// FUNCTION: TITANIUM 0x0040AC55
char* GuildTable_guess::GetName_guess(int index) {
    if (index < 0 || index >= 0x5dc) {
        return "Unknown Guild";
    }
    char* name = names_04c[index];
    if (*name != 0) {
        return name;
    }
    if (FUN_00576e80_guess() - lastTick_1798c > 2) {
        lastTick_1798c = FUN_00576e80_guess();
        char* text = (char*)g_lookupGlobals_guess +
                     g_lookupGlobals_guess->offset_008->vbaseOffset_0004_guess + 0x44;
        unsigned int length = strlen(text) + 1;
        EQSendMessage(g_packetTarget_guess, 0x6d5d, text, length, 1);
    }
    return "Unknown Guild";
}

// Message 0x17A2: guild id, player name, member `first` and note `second` (the layout of EQEmu
// GuildUpdate_PublicNote, so probably the public-note update). Nothing when the player has no guild.
// FUNCTION: TITANIUM 0x0040ACBF
void GuildTable_guess::SendGuildPublicNote_guess(const char* first, const char* second) {
    if (g_lookupGlobals_guess->value_e0c != -1) {
        GuildMessage_guess message;
        memset(&message, 0, sizeof(message));
        Convert_guess(message.text_004, (char*)g_lookupGlobals_guess +
                      g_lookupGlobals_guess->offset_008->vbaseOffset_0004_guess + 0x44);
        Convert_guess(message.text_044, first);
        Convert_guess(message.text_084, second);
        message.id_000 = g_lookupGlobals_guess->value_e0c;
        EQSendMessage(g_packetTarget_guess, 0x17a2, &message,
                           sizeof(message), 1);
    }
}

// OP_GuildDemote: player name and member name. Refused with string 516 (target is same/higher rank) when
// the member is someone else whose rank is not below the player's (profile +0xE10).
// FUNCTION: TITANIUM 0x0040AD67
void RequestOwner_guess::SendGuildDemote_guess(DataObject_guess* data) {
    char format[0x200];
    char message[0x80];
    SelectedIndex_guess* selected = g_selectedIndex_guess;
    if (selected->state_e10 <= data->value_5c &&
        CompareValue_guess((int)((char*)selected + selected->vbtable_0008_guess->vbaseOffset_0004_guess + 0x44),
                           (const int*)data->text_10) != 0) {
        FormatText_guess(format, 0x204, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(format);
        return;
    }
    memset(message, 0, 0x80);
    selected = g_selectedIndex_guess;
    CopyText_guess(message,
                   (char*)selected + selected->vbtable_0008_guess->vbaseOffset_0004_guess + 0x44);
    CopyText_guess(message + 0x40, data->text_10);
    EQSendMessage(g_packetTarget_guess, OP_GuildDemote, message, 0x80, 1);
}

// OP_GuildManageBanker: the member's banker flags with `mask` set or cleared. Only a leader (rank 2) may;
// others get string 516, the same/higher-rank text, though rank is not the reason.
// FUNCTION: TITANIUM 0x0040AE42
void RequestOwner_guess::SendGuildBankerFlags_guess(DataObject_guess* data, unsigned int mask,
                                     char set) {
    RequestBuffers_guess buffers;
    if (g_selectedIndex_guess->state_e10 < 2) {
        FormatText_guess(buffers.format_000, 0x204, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffers.format_000);
    } else {
        unsigned int flags = data->value_54;
        if (set != 0) {
            flags |= mask;
        } else {
            flags &= ~mask;
        }
        buffers.message_200.flags_084 = flags;
        CopyText_guess(buffers.message_200.text_044, data->text_10);
        SelectedIndex_guess* state = g_selectedIndex_guess;
        char* source = (char*)state + state->vbtable_0008_guess->vbaseOffset_0004_guess + 0x44;
        CopyText_guess(buffers.message_200.text_004, source);
        EQSendMessage(g_packetTarget_guess, OP_GuildManageBanker,
                           &buffers.message_200, 0x88, 1);
    }
}


// EXTERNAL: TITANIUM 0x00433D68 ReadBigEndianUInt32_guess
int __cdecl ReadBigEndianUInt32_guess(const unsigned char* bytes);


// OP_GuildMemberList body: a big-endian count, then per member the name, level, banker flags, class, rank,
// last-on time, tribute on, total tribute, last tribute, tribute flag, public note and zone (EQEmu
// GuildMemberEntry_Struct, zone instance and id read as one int). Refreshes the guild management and
// LFGuild windows (0x991C40).
// FUNCTION: TITANIUM 0x0040AF04
void ListOwner_guess::LoadGuildMemberList_guess(const unsigned char* stream) {
    int total = ReadBigEndianUInt32_guess(stream);
    stream += 4;
    if (g_soundManager_guess != 0) {
        g_soundManager_guess->Refresh_guess();
    }
    Clear_guess();
    if (total > 0) {
        int remaining = total;
        do {
            DataObject_guess* data;
            DataObject_guess* memory = (DataObject_guess*)operator new(0x274);
            if (memory != 0) {
                data = memory->Initialize_guess();
            } else {
                data = 0;
            }
            CopyText_guess(data->text_10, stream);
            stream += strlen(data->text_10) + 1;
            data->value_50 = ReadBigEndianUInt32_guess(stream);
            stream += 4;
            data->value_54 = ReadBigEndianUInt32_guess(stream);
            stream += 4;
            data->value_58 = ReadBigEndianUInt32_guess(stream);
            stream += 4;
            data->value_5c = ReadBigEndianUInt32_guess(stream);
            stream += 4;
            data->value_60 = ReadBigEndianUInt32_guess(stream);
            stream += 4;
            data->flag_264 = ReadBigEndianUInt32_guess(stream) != 0;
            stream += 4;
            data->value_268 = ReadBigEndianUInt32_guess(stream);
            stream += 4;
            data->value_26c = ReadBigEndianUInt32_guess(stream);
            stream += 4;
            data->flag_270 = ReadBigEndianUInt32_guess(stream) != 0;
            stream += 4;
            CopyText_guess(data->buffer_64, stream);
            stream += strlen(data->buffer_64) + 1;
            data->value_08 = ReadBigEndianUInt32_guess(stream);
            stream += 4;
            if (data->value_08 != 0) {
                data->flag_04 = 1;
            }
            Add_guess((int*)data);
            --remaining;
        } while (remaining != 0);
    }
    if (g_soundManager_guess != 0) {
        g_soundManager_guess->SortMembers_guess(0, 1);
        g_soundManager_guess->SetPlayerCount_guess(count);
    }
    if (pinstCLFGuildWnd_guess != 0) {
        pinstCLFGuildWnd_guess->Reset_00529b96_guess();
    }
    changed_179b4 = 1;
    changed_17994 = 1;
}

// OP_GuildMemberDelete. When the deleted member is the player, the MOTD and whole list are dropped and the
// guild tribute master window (0x991AC8) is hidden if open.
// FUNCTION: TITANIUM 0x0040B079
void ListOwner_guess::Remove_guess(RemoveRequest_guess* request, int unused_guess) {
    ListNode_guess* node = head;
    ListNode_guess* previous = 0;
    if (node != 0) {
        do {
            if (CompareValue_guess((int)request->text_004,
                                   (const int*)node->text_10) == 0) {
                if (CompareValue_guess((int)request->text_004,
                        (char*)g_selectedIndex_guess +
                        g_selectedIndex_guess->vbtable_0008_guess->vbaseOffset_0004_guess + 0x44) == 0) {
                    memset(text_1774c, 0, 0x200);
                    memset(text_1794c, 0, 0x40);
                    if (g_soundManager_guess != 0) {
                        g_soundManager_guess->Refresh_guess();
                    }
                    if (pinstCGuildTributeMasterWnd_guess != 0 && pinstCGuildTributeMasterWnd_guess->dShow != 0) {
                        pinstCGuildTributeMasterWnd_guess->Show(0, 1);
                    }
                    Clear_guess();
                    return;
                }
                if (previous == 0) {
                    head = node->next;
                } else {
                    previous->next = node->next;
                }
                if (g_soundManager_guess != 0) {
                    g_soundManager_guess->RemoveMember_guess(node);
                }
                --count;
                if (g_soundManager_guess != 0) {
                    g_soundManager_guess->SetPlayerCount_guess(count);
                }
                changed_17994 = 1;
                changed_179b4 = 1;
                free(node);
                return;
            }
            previous = node;
            node = node->next;
        } while (node != 0);
    }
}

// Message 0x32CF: a member's public note (+0x64) from the request text; probably the note-update reply.
// FUNCTION: TITANIUM 0x0040B175
void LookupTable_guess::ConvertRequest_guess(Request_guess* request) {
    LookupNode_guess* node = Find_guess((int)&request->key_004);
    if (node != 0) {
        Convert_guess(node->text_064, request->text_044);
        ((AudioState_guess*)this)->RefreshGuildMember_guess((int)node);
    }
}

// Message 0x6966: a member's rank (request +0x08) and banker flags (+0x4C), and the player's own flags
// (profile +0xE14) when it names the player.
// FUNCTION: TITANIUM 0x0040B1AA
void LookupTable_guess::UpdateRequest_guess(UpdateData_guess* request) {
    LookupNode_guess* node = Find_guess((int)request->text_00c);
    if (node != 0) {
        node->value_05c = request->value_008;
        node->value_054 = request->value_04c;
        ((AudioState_guess*)this)->RefreshGuildMember_guess((int)node);
        flag_17994 = 1;
        flag_179b4 = 1;
    }
    if (_strcmp((char*)g_lookupGlobals_guess + g_lookupGlobals_guess->offset_008->vbaseOffset_0004_guess + 0x44,
                request->text_00c) == 0) {
        g_lookupGlobals_guess->value_e14 = request->value_04c;
    }
}

// OP_GuildMemberLevel: stores the member's new level.
// FUNCTION: TITANIUM 0x0040B213
void LookupTable_guess::SetGuildMemberLevel_guess(Request_guess* request) {
    LookupNode_guess* node = Find_guess((int)&request->key_004);
    if (node != 0) {
        node->level_0050_guess = request->level_0044_guess;
        ((AudioState_guess*)this)->RefreshGuildMember_guess((int)node);
        flag_179b4 = 1;
    }
}

// OP_GuildMemberRename: writes the new name over the entry's name and renames it in the window.
// FUNCTION: TITANIUM 0x0040B242
void LookupTable_guess::RenameGuildMember_guess(Request_guess* request) {
    LookupNode_guess* node = Find_guess((int)&request->key_004);
    if (node != 0) {
        Convert_guess((char*)&node->value, request->text_044);
        if (g_soundManager_guess != 0) {
            g_soundManager_guess->RenameMember_guess((int)&request->key_004, request->text_044);
        }
    }
}

// Guild tribute cost, recomputed when stale (Recalculate_guess).
// FUNCTION: TITANIUM 0x0040B27A
int ListOwner_guess::GetValue_guess() {
    if (changed_179b4 != 0) {
        Recalculate_guess();
    }
    return value_179b0;
}

// Guild object constructor: no members, then everything emptied including the 1500 guild names
// (0x0040ABBF).
// FUNCTION: TITANIUM 0x0040B293
ListOwner_guess::ListOwner_guess() : head(0) {
    Initialize_guess(1);
}

// Scalar deleting destructor of the guild object (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x0040B2AB
ListOwner_guess* ListOwner_guess::Delete_guess(unsigned int flags) {
    this->ListOwner_guess::~ListOwner_guess();
    if (flags & 1) {
        free(this);
    }
    return this;
}

struct Entry_guess {
    int key;
    int unknown_04;
};

struct Table_guess {
    unsigned char unknown_00000[0x17998];
    int count; // 0x17998
    int unknown_1799c;
    Entry_guess entries[2]; // 0x179a0; keys at 0x179a0 and 0x179a8
    int Find_guess(int value);
    void SpendGuildFavor_guess(int amount);
};

// Which of the two guild tribute slots holds tribute `value`, or -1.
// FUNCTION: TITANIUM 0x0040AB01
int Table_guess::Find_guess(int value) {
    int index = 0;
    Entry_guess* entry = entries;
    do {
        if (entry->key == value) {
            return index;
        }
        ++index;
        ++entry;
    } while (index < 2);
    return -1;
}

// Takes `amount` off the guild's tribute favor (+0x17998), not below 0; probably favor, from tu_027.
// FUNCTION: TITANIUM 0x0040AB20
void Table_guess::SpendGuildFavor_guess(int amount) {
    count -= amount;
    if (count < 0) {
        count = 0;
    }
}

struct String_guess {
    unsigned char data[0x1c];
    // EXTERNAL: TITANIUM 0x004032F1 String_guess::String_guess
    String_guess(const String_guess& value);
    // EXTERNAL: TITANIUM 0x0040291E String_guess::Tidy_guess
    void Tidy_guess(bool deallocate, unsigned int capacity);
    // EXTERNAL: TITANIUM 0x0040B488 String_guess::~String_guess
    ~String_guess() ;
};

struct StringTemporary_guess {
    unsigned char data[0x1c];
    // EXTERNAL: TITANIUM 0x004032F1 StringTemporary_guess::StringTemporary_guess
    StringTemporary_guess(const String_guess& value);
    // EXTERNAL: TITANIUM 0x0040291E StringTemporary_guess::Tidy_guess
    void Tidy_guess(bool deallocate, unsigned int capacity);
    ~StringTemporary_guess() { Tidy_guess(true, 0); }
};

// EXTERNAL: TITANIUM 0x0040B2ED ConstructString_guess
void __cdecl ConstructString_guess(String_guess* destination, const String_guess* value);

// STL helpers for std::vector<std::string> (28-byte strings): copy-construct a range, and on an
// exception destroy what was built and rethrow.
// FUNCTION: TITANIUM 0x0040B3C1
String_guess* __cdecl CopyStringRange_guess(const String_guess* first,
                                           const String_guess* last,
                                           String_guess* result) {
    String_guess* begin = result;
    try {
        while (first != last) {
            ConstructString_guess(result, first);
            ++result;
            ++first;
        }
    } catch (...) {
        while (result != begin) {
            (--result)->~String_guess();
        }
        throw;
    }
    return result;
}

// Fill-construct twin of CopyStringRange_guess.
// FUNCTION: TITANIUM 0x0040B4BF
void __cdecl FillStringCopies_guess(String_guess* first, unsigned int count, const String_guess* value) {
    String_guess* begin = first;
    try {
        while (count > 0) {
            ConstructString_guess(first, value);
            --count;
            ++first;
        }
    } catch (...) {
        while (first != begin) {
            (--first)->~String_guess();
        }
        throw;
    }
}

struct StringVector_guess {
    unsigned char unknown_00[4];
    String_guess* first;
    String_guess* last;
    String_guess* end;
    // EXTERNAL: TITANIUM 0x0040AB9E StringVector_guess::Capacity_guess
    int Capacity_guess();
    // EXTERNAL: TITANIUM 0x0040AB88 StringVector_guess::Size_guess
    int Size_guess();
    // EXTERNAL: TITANIUM 0x0040B31A StringVector_guess::LengthError_guess
    void LengthError_guess();
    // EXTERNAL: TITANIUM 0x0040B56D StringVector_guess::FillConstruct_guess
    String_guess* FillConstruct_guess(String_guess* destination, unsigned int count,
                                      const StringTemporary_guess* value);
    void InsertCopies_guess(String_guess* position, unsigned int count,
                            const String_guess* value);
};

void* __cdecl operator new(unsigned int size);
// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* memory);

// EXTERNAL: TITANIUM 0x0040B4A2 MoveConstructRange_guess
String_guess* __cdecl MoveConstructRange_guess(String_guess* first, String_guess* last,
                                               String_guess* destination,
                                               StringVector_guess* owner);
// EXTERNAL: TITANIUM 0x0040B46E DestroyStringRange_guess
void __cdecl DestroyStringRange_guess(String_guess* first, String_guess* last,
                                     StringVector_guess* owner);
// EXTERNAL: TITANIUM 0x0040B35A AssignStringRange_guess
void __cdecl AssignStringRange_guess(String_guess* first, String_guess* last,
                                     const StringTemporary_guess* value);
// EXTERNAL: TITANIUM 0x0040B488 CopyBackwardStrings_guess
void __cdecl CopyBackwardStrings_guess(String_guess* first, String_guess* last,
                                       String_guess* destination);

// std::vector<std::string>::insert(position, count, value), the MSVC6 _Insert_n: grows by half again
// (at least to fit); 0x09249249 is max_size (4 GB / 28).
// FUNCTION: TITANIUM 0x0040B58F
// @early-stop: budget, structural ndiff=96
void StringVector_guess::InsertCopies_guess(String_guess* position, unsigned int count,
                                           const String_guess* value) {
    StringTemporary_guess copy(*value);
    unsigned int oldCapacity = Capacity_guess();
    if (count != 0) {
        if (0x09249249U - Size_guess() < count) {
            LengthError_guess();
        }
        if (oldCapacity < Size_guess() + count) {
            unsigned int newCapacity;
            if (0x09249249U - (oldCapacity >> 1) < oldCapacity) {
                newCapacity = 0;
            } else {
                newCapacity = oldCapacity + (oldCapacity >> 1);
            }
            if (newCapacity < Size_guess() + count) {
                newCapacity = Size_guess() + count;
            }
            String_guess* storage = (String_guess*)operator new(newCapacity * 0x1c);
            String_guess* copied = storage;
            copied = (String_guess*)MoveConstructRange_guess(first, position, copied, this);
            copied = FillConstruct_guess(copied, count, &copy);
            MoveConstructRange_guess(position, last, copied, this);
            unsigned int size = Size_guess();
            if (first != 0) {
                DestroyStringRange_guess(first, last, this);
                operator delete(first);
            }
            end = storage + newCapacity;
            last = storage + size + count;
            first = storage;
        } else {
            String_guess* oldLast = last;
            if ((unsigned int)(oldLast - position) < count) {
                MoveConstructRange_guess(position, oldLast, position + count, this);
                FillConstruct_guess(oldLast, count - (unsigned int)(oldLast - position), &copy);
                last += count;
                AssignStringRange_guess(position, oldLast, &copy);
            } else {
                String_guess* suffix = oldLast - count;
                last = MoveConstructRange_guess(suffix, oldLast, oldLast, this);
                CopyBackwardStrings_guess(position, suffix, oldLast);
                AssignStringRange_guess(position, position + count, &copy);
            }
        }
    }
}

struct Cleanup_guess {
    unsigned char data[0x10];
    // EXTERNAL: TITANIUM 0x0040B540 Cleanup_guess::Dispose_guess
    void Dispose_guess();
    void Forward_guess();
};

// Thunk to GuildStringVector_guess's destructor (0x40B540).
// FUNCTION: TITANIUM 0x0040B820
void Cleanup_guess::Forward_guess() {
    return Dispose_guess();
}

struct StringPair_guess {
    String_guess first;
    Cleanup_guess middle;
    String_guess last;
    void Release_guess();
};

// Really GuildRecord_guess's destructor (same VA): the two strings and the name vector, in reverse order.
// FUNCTION: TITANIUM 0x0040B867
void StringPair_guess::Release_guess() {
    last.Tidy_guess(true, 0);
    middle.Dispose_guess();
    first.Tidy_guess(true, 0);
}

struct GuildNameMessage_guess {
    int index_00;          // 0x00
    char text_04[0x40];    // 0x04
};

struct GuildStatusMessage_guess {
    unsigned char unknown_00[0x04];
    int key_004;           // 0x04
    unsigned char unknown_08[0x3c];
    int value_044;         // 0x44
    int value_048;         // 0x48
};

struct GuildErrorMessage_guess {
    int type_000;                     // 0x00
    char flag_004;                    // 0x04
    unsigned char unknown_005[0x141]; // 0x05
    char text_146[0x7d02];            // 0x146
};

struct GuildNamesMessage_guess {
    unsigned char unknown_00[0x40];   // 0x00
    char names_040[0x17700];          // 0x40
};

struct GuildLoadMessage_guess {
    char text_000[1];                 // 0x00
};

struct PlayerNameGlobals_guess {
    unsigned char unknown_000[0x08];  // 0x00
    LookupOffset_guess* offset_008;   // 0x08
    unsigned char unknown_00c[0x38];  // 0x0c
    char region_044[0xdc8];           // 0x44
};

#define g_playerNameGlobals_guess EQ_GLOBAL(PlayerNameGlobals_guess*, 0x00905D00)

struct GuildString_guess {
    unsigned int allocator_000;  // 0x00
    char buffer_004[16];         // 0x04, small-string buffer / pointer
    unsigned int length_014;     // 0x14
    unsigned int capacity_018;   // 0x18
    // EXTERNAL: TITANIUM 0x00403631 ??0GuildString_guess@@QAE@PBD@Z
    GuildString_guess(const char* text);
    // EXTERNAL: TITANIUM 0x0040291E GuildString_guess::Tidy_guess
    void Tidy_guess(bool deallocate, unsigned int capacity);
    ~GuildString_guess() { Tidy_guess(true, 0); }
};

struct GuildStringVector_guess {
    unsigned int allocator_000;          // 0x00
    GuildString_guess* first_004;        // 0x04
    GuildString_guess* last_008;         // 0x08
    GuildString_guess* end_00c;          // 0x0c
    GuildStringVector_guess() {
        first_004 = 0;
        last_008 = 0;
        end_00c = 0;
    }
    // EXTERNAL: TITANIUM 0x0040B7B2 ??0GuildStringVector_guess@@QAE@ABU0@@Z
    GuildStringVector_guess(const GuildStringVector_guess& other);
    GuildStringVector_guess* CopyConstruct_guess(const GuildStringVector_guess& other);
    // EXTERNAL: TITANIUM 0x0040B428 GuildStringVector_guess::Allocate_guess
    bool Allocate_guess(unsigned int count);
    // EXTERNAL: TITANIUM 0x0040B88B ?push_back@GuildStringVector_guess@@QAEXABUGuildString_guess@@@Z
    void push_back(const GuildString_guess& value);
    // EXTERNAL: TITANIUM 0x0040AB88 ?size@GuildStringVector_guess@@QBEIXZ
    unsigned int size() const;
    // EXTERNAL: TITANIUM 0x0040B540 ??1GuildStringVector_guess@@QAE@XZ
    ~GuildStringVector_guess();
};

// EXTERNAL: TITANIUM 0x0040B4A2 MoveConstructGuildStrings_guess
GuildString_guess* __cdecl MoveConstructGuildStrings_guess(GuildString_guess* first,
                                                           GuildString_guess* last,
                                                           GuildString_guess* destination,
                                                           GuildStringVector_guess* owner);

// Really the GuildStringVector_guess copy constructor (its EXTERNAL names the same VA).
// FUNCTION: TITANIUM 0x0040B7B2
// @early-stop: budget, structural ndiff=19
GuildStringVector_guess* GuildStringVector_guess::CopyConstruct_guess(const GuildStringVector_guess& other) {
    GuildStringVector_guess* destination = this;
    const GuildStringVector_guess* input = &other;
    if (destination->Allocate_guess(input->size())) {
        try {
            destination->last_008 = MoveConstructGuildStrings_guess(
                input->first_004, input->last_008, destination->first_004, destination);
        } catch (...) {
            destination->last_008 = destination->first_004;
            throw;
        }
    }
    return destination;
}

struct GuildRecord_guess {
    GuildString_guess first_000;            // 0x00
    GuildStringVector_guess middle_01c;     // 0x1c
    GuildString_guess last_02c;             // 0x2c
    unsigned char flag_048;                 // 0x48
    unsigned char flag_049;                 // 0x49
    // EXTERNAL: TITANIUM 0x0042BA5E GuildRecord_guess::GuildRecord_guess
    GuildRecord_guess(GuildString_guess first, GuildStringVector_guess middle,
                      GuildString_guess last, bool flag);
    // EXTERNAL: TITANIUM 0x0040B867 GuildRecord_guess::~GuildRecord_guess
    ~GuildRecord_guess();
};

struct GuildList_guess {
    unsigned char unknown_000[0x2c];  // 0x00
    // EXTERNAL: TITANIUM 0x00428534 GuildList_guess::Find_guess
    GuildRecord_guess* Find_guess(const GuildString_guess& name);
    // EXTERNAL: TITANIUM 0x0042BF38 GuildList_guess::Add_guess
    void Add_guess(GuildRecord_guess& record);
    // EXTERNAL: TITANIUM 0x0042BF49 GuildList_guess::Remove_guess
    void Remove_guess(GuildRecord_guess* record);
};

struct GuildManager_guess;

struct GuildRoot_guess {
    // EXTERNAL: TITANIUM 0x00495250 GuildRoot_guess::GetManager_guess
    GuildManager_guess* GetManager_guess();
};

struct GuildManager_guess {
    unsigned char unknown_000[0x60];  // 0x00
    GuildList_guess list_060;         // 0x60
};

#define g_guildRoot_guess EQ_GLOBAL(GuildRoot_guess*, 0x00988DF0)

struct GuildManagement_guess {
    unsigned char unknown_000[0x04];   // 0x00
    char flag_04;                      // 0x04
    unsigned char unknown_005[0x3f];   // 0x05
    int count_044;                     // 0x44
    ListNode_guess* head_048;          // 0x48
    char names_04c[0x5dc][0x40];       // 0x4c
    char text_1774c[0x200];            // 0x1774c
    char text_1794c[0x40];             // 0x1794c
    int value_1798c;                   // 0x1798c
    int value_17990;                   // 0x17990
    unsigned char changed_17994;       // 0x17994
    unsigned char unknown_17995[0x07]; // 0x17995
    int value_1799c;                   // 0x1799c
    int values_179a0[4];               // 0x179a0
    int value_179b0;                   // 0x179b0
    unsigned char changed_179b4;       // 0x179b4
    void HandleMessage_guess(void* connection, unsigned int messageId, void* data, int size);
};

// EXTERNAL: TITANIUM 0x00401B28 FUN_00401b28_guess
PacketSource_guess* __cdecl FUN_00401b28_guess(unsigned int id);

// EXTERNAL: TITANIUM 0x0060DA00 memcpy
void* __cdecl memcpy(void* destination, const void* source, unsigned int size);

// EXTERNAL: TITANIUM 0x0060E450 strcpy
char* __cdecl strcpy(char* destination, const char* source);

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* destination, const char* format, ...);

// Guild messages from the world server. Names from opcodes.h; 0x6966, 0x2EC9, 0x32CF and 0xF4D have no
// EQEmu name (their handlers say: rank/banker, a guild name like OP_GuildRenameGuild, public note,
// zone/online). OP_GuildsList carries all 1500 64-byte names; any other size is reported back as an
// OP_CrashDump. OP_GuildInvite is ignored here.
// The cases that break (rename, add, delete, the player's own OP_SpawnAppearance, member list) rebuild
// the "Guild" group of member names in the mail manager's address list, or drop it when empty.
// FUNCTION: TITANIUM 0x0040B8CB
// @early-stop: budget, structural ndiff=241
void GuildManagement_guess::HandleMessage_guess(void* connection, unsigned int messageId,
                                                void* data, int size) {
    switch (messageId) {
    case OP_GuildMemberRename:
        ((LookupTable_guess*)this)->RenameGuildMember_guess((Request_guess*)data);
        break;
    case OP_SpawnAppearance: {
        if (size != 8) {
            return;
        }
        PacketSource_guess* expected = g_packetSource_guess;
        PacketSource_guess* found = expected;
        if (*(unsigned short*)data != 0) {
            found = FUN_00401b28_guess(*(unsigned short*)data);
        }
        if (found == 0 || found != expected) {
            return;
        }
        break;
    }
    case OP_GuildMemberAdd:
        ((ListOwner_guess*)this)->AddFromRequest_guess((CreateRequest_guess*)data, size);
        break;
    case OP_GuildMemberDelete:
        ((ListOwner_guess*)this)->Remove_guess((RemoveRequest_guess*)data, size);
        break;
    case 0x6966:
        ((LookupTable_guess*)this)->UpdateRequest_guess((UpdateData_guess*)data);
        return;
    case OP_GuildsList: {
        if (size == 0x17740) {
            memcpy(names_04c, ((GuildNamesMessage_guess*)data)->names_040, 0x17700);
            return;
        }
        GuildErrorMessage_guess message;
        memset(&message, 0, sizeof(message));
        message.type_000 = 1;
        message.flag_004 = 1;
        if (g_lookupGlobals_guess != 0) {
            // OP_CrashDump body: type 1, flag 1, the text at +0x146.
            sprintf(message.text_146, "Player %s --MsgId %8x, Sizes differ, there is a problem msg size %d, m_guildNames size %d",
                    &g_playerNameGlobals_guess->region_044[
                        g_playerNameGlobals_guess->offset_008->vbaseOffset_0004_guess],
                    messageId, size, 0x17700);
        } else {
            sprintf(message.text_146, "MsgID %8x, Sizes differ, there is a problem msg size %d, m_guildNames size %d",
                    messageId, size, 0x17700);
        }
        EQSendMessage(&connection, OP_CrashDump, &message, sizeof(message), 1);
        return;
    }
    case OP_GuildRenameGuild:
    case 0x2ec9: {
        GuildNameMessage_guess* message = (GuildNameMessage_guess*)data;
        if (message->index_00 >= 0 && message->index_00 < 0x5dc) {
            strcpy(names_04c[message->index_00], message->text_04);
        }
        return;
    }
    case OP_GuildMemberLevel:
        ((LookupTable_guess*)this)->SetGuildMemberLevel_guess((Request_guess*)data);
        return;
    case 0x32cf:
        ((LookupTable_guess*)this)->ConvertRequest_guess((Request_guess*)data);
        return;
    case OP_GuildDeleteGuild:
        ((ListOwner_guess*)this)->ClearRecord_guess((int*)data);
        return;
    case OP_GuildInvite:
        return;
    case OP_GuildMemberList: {
        char text[0x40];
        strcpy(text, (const char*)data);
        ((ListOwner_guess*)this)->LoadGuildMemberList_guess(
            (const unsigned char*)&((GuildLoadMessage_guess*)data)->text_000[strlen(text) + 1]);
        break;
    }
    case 0xf4d: {
        GuildStatusMessage_guess* message = (GuildStatusMessage_guess*)data;
        DataObject_guess* node = (DataObject_guess*)((LookupTable_guess*)this)
            ->Find_guess((int)&message->key_004);
        if (node != 0) {
            node->value_08 = message->value_044;
            if (node->value_08 == 0) {
                node->flag_04 = 0;
            } else {
                node->value_60 = message->value_048;
                node->flag_04 = 1;
            }
            ((AudioState_guess*)this)->RefreshGuildMember_guess((int)node);
            changed_17994 = 1;
            changed_179b4 = 1;
        }
        return;
    }
    default:
        return;
    }

    if (g_guildRoot_guess != 0) {
        GuildManager_guess* manager = g_guildRoot_guess->GetManager_guess();
        if (manager != 0) {
            GuildStringVector_guess names;
            for (ListNode_guess* node = head_048; node != 0; node = node->next) {
                names.push_back(GuildString_guess(node->text_10));
            }
            if (names.size() > 0) {
                GuildRecord_guess record("Guild", names, "", true);
                manager->list_060.Add_guess(record);
            } else {
                GuildRecord_guess* record =
                    manager->list_060.Find_guess(GuildString_guess("Guild"));
                if (record != 0) {
                    manager->list_060.Remove_guess(record);
                }
            }
        }
    }
}

struct ForwardTarget_guess {
    // EXTERNAL: TITANIUM 0x005E49B0 ForwardTarget_guess::Dispose_guess
    void Dispose_guess();
};

struct ForwardPointer_guess {
    ForwardTarget_guess* target;
    void Dispose_guess();
};

// Thunk: ends the guard (0x5E49B0).
// FUNCTION: TITANIUM 0x0040BCE4
void ForwardPointer_guess::Dispose_guess() {
    return target->Dispose_guess();
}

struct VirtualTarget_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
};

struct VirtualPointer_guess {
    VirtualTarget_guess* target;
    void Dispatch_guess();
};

// Thunk: virtual slot 1 of the target (its release).
// FUNCTION: TITANIUM 0x0040BCEB
void VirtualPointer_guess::Dispatch_guess() {
    return target->Slot01_guess();
}

// `second - first`, capped at INT_MAX.
// FUNCTION: TITANIUM 0x0040BCF2
int __cdecl SaturateDifference_guess(__int64 first, __int64 second) {
    __int64 difference = second - first;
    if (difference > 0x7fffffff) {
        return 0x7fffffff;
    }
    return (int)difference;
}

// EXTERNAL: TITANIUM 0x0060F455 _isspace
extern "C" int __cdecl _isspace(int character);

// Reads one field of a delimited line into `output` (at most size - 1 chars) and moves `cursor` past the
// delimiter. Skips leading space; a leading quoted part is copied without its quotes and the rest of the
// field is appended; trailing space is trimmed. Returns the length.
// FUNCTION: TITANIUM 0x0040C0F2
int __cdecl ParseField_guess(char* output, int size, char** cursor, char delimiter) {
    char* start = output;
    char* end = start + size - 1;
    char* p = *cursor;
    char* dst = start;
    while (_isspace(*p)) {
        ++p;
    }
    if (*p == '"') {
        ++p;
        char c = *p;
        if (c != '"') {
            do {
                if (c == 0) {
                    break;
                }
                if (dst != end) {
                    *dst = c;
                    ++dst;
                }
                ++p;
                c = *p;
            } while (c != '"');
            if (*p == '"') {
                ++p;
            }
        } else {
            ++p;
        }
    }
    char c = 0;
    while ((c = *p) != 0 && c != '\n' && c != '\r' && c != delimiter) {
        if (dst != end) {
            *dst = c;
            ++dst;
        }
        ++p;
    }
    *dst = 0;
    if (*p == delimiter) {
        ++p;
    }
    *cursor = p;
    while (dst > start && _isspace(dst[-1])) {
        *--dst = 0;
    }
    return (int)dst - (int)start;
}

struct TickClock_guess {
    int unknown_00;
    void* lock_04;
    // EXTERNAL: TITANIUM 0x005E4C80 TickClock_guess::TickClock_guess
    TickClock_guess();
    // EXTERNAL: TITANIUM 0x005E4B30 TickClock_guess::Now_guess
    __int64 Now_guess();
    ~TickClock_guess();
};

// Current time from one static clock (0x5E4B30), shared by the chat client and tu_017/tu_062.
// FUNCTION: TITANIUM 0x0040C194
__int64 __cdecl GetClockStamp_guess() {
    static TickClock_guess clock;
    return clock.Now_guess();
}

// Time since a GetClockStamp_guess value, capped at INT_MAX; the callers treat it as milliseconds.
// FUNCTION: TITANIUM 0x0040C1E2
int __cdecl ClockElapsed_guess(__int64 value) {
    return SaturateDifference_guess(value, GetClockStamp_guess());
}

struct Guard_guess {
    // EXTERNAL: TITANIUM 0x005E49A0 Guard_guess::Begin_guess
    void Begin_guess();
    // EXTERNAL: TITANIUM 0x005E49B0 Guard_guess::End_guess
    void End_guess();
};

struct QueryResult_guess;

struct Owner_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    unsigned char unknown_004[0x80];
    int value_084;
    unsigned char unknown_088[0x174];
    int value_1fc;
    unsigned char unknown_200[0x24];
    Guard_guess guard;
    void Set_guess(int value);
    int Get_guess();
    // EXTERNAL: TITANIUM 0x005E6EC0 Owner_guess::Append_guess
    void Append_guess(int kind, char* data, unsigned int length);
    // EXTERNAL: TITANIUM 0x005E65B0 Owner_guess::Finish_guess
    void Finish_guess();
    // EXTERNAL: TITANIUM 0x005E68F0 Owner_guess::WriteData_guess
    void WriteData_guess(int value, int kind);
    // EXTERNAL: TITANIUM 0x005E5A60 Owner_guess::Query_guess
    void Query_guess(int kind, QueryResult_guess* result);
    void Flush_guess(int value);
};

// Connection user data under its lock; the chat client stores itself here.
// FUNCTION: TITANIUM 0x0040BE64
void Owner_guess::Set_guess(int value) {
    guard.Begin_guess();
    value_1fc = value;
    guard.End_guess();
}

// Connection state under its lock: 0 connecting, 1 connected (as GetStatus_guess reads it).
// FUNCTION: TITANIUM 0x0040BE8B
int Owner_guess::Get_guess() {
    guard.Begin_guess();
    int result = value_084;
    guard.End_guess();
    return result;
}

struct OwnerScope_guess {
    Owner_guess* owner;     // 0x00
    OwnerScope_guess(Owner_guess* value) : owner(value) {
        owner->Slot00_guess();
    }
    ~OwnerScope_guess() {
        owner->Slot01_guess();
    }
};

struct SectionLock_guess {
    Guard_guess* guard;     // 0x00
    SectionLock_guess(Guard_guess* value) : guard(value) {
        guard->Begin_guess();
    }
    ~SectionLock_guess() {
        guard->End_guess();
    }
};

// Disconnects (WriteData_guess kind 6) inside the connection's own scope and lock.
// FUNCTION: TITANIUM 0x0040BEAE
void Owner_guess::Flush_guess(int value) {
    OwnerScope_guess scope(this);
    SectionLock_guess lock(&guard);
    WriteData_guess(value, 6);
}

struct StatusHolder_guess {
    unsigned char unknown_00[0x14];
    char flag_14;
    unsigned char unknown_15[0x3];
    Owner_guess* target_18;
    int GetStatus_guess();
    void Send_guess(const char* value);
};

// EXTERNAL: TITANIUM 0x0060E450 Convert_guess
void __cdecl Convert_guess(char* destination, const char* source);

// Chat-server state for CEverQuest: 0 no connection, 2 connecting, 3 connected but not logged in,
// 1 logged in.
// FUNCTION: TITANIUM 0x0040BF0F
int StatusHolder_guess::GetStatus_guess() {
    if (target_18 != 0) {
        int state = target_18->Get_guess();
        switch (state) {
        case 0:
            return 2;
        case 1:
            return (flag_14 == 0) * 2 + 1;
        }
    }
    return 0;
}

// Sends a chat command: packet type 2 and the text, on channel 4; only once logged in.
// FUNCTION: TITANIUM 0x0040BF3D
void StatusHolder_guess::Send_guess(const char* value) {
    if (flag_14 != 0 && target_18 != 0) {
        char buffer[0x2000];
        buffer[0] = 2;
        Convert_guess(buffer + 1, value);
        char* end = buffer + 2 + strlen(buffer + 1);
        target_18->Append_guess(4, buffer, (unsigned int)(end - buffer));
        target_18->Finish_guess();
    }
}

struct SortableArray_guess {
    unsigned char unknown_00[0xc8];
    void* values;
    unsigned int count;
    void Sort_guess();
};

// EXTERNAL: TITANIUM 0x0060EE40 _qsort
void __cdecl _qsort(void* base, unsigned int count, unsigned int size,
                    int (__cdecl *compare)(const void*, const void*));

// EXTERNAL: TITANIUM 0x0040BFC9 CompareSortValues_guess
int __cdecl CompareSortValues_guess(const void* first, const void* second);

// Sorts the 4-byte entries at +0xC8 (the type-6 list).
// FUNCTION: TITANIUM 0x0040C00B
void SortableArray_guess::Sort_guess() {
    _qsort(values, count, 4, CompareSortValues_guess);
}

struct NameTable_guess {
    unsigned char unknown_00[0x0c];
    char** names;
    int count;
    int Find_guess(char* name);
};

// EXTERNAL: TITANIUM 0x00621E9C __stricmp
int __cdecl __stricmp(const char* first, const char* second);

// Index of channel `name` in the joined-channel list (case-insensitive), or -1.
// FUNCTION: TITANIUM 0x0040C027
int NameTable_guess::Find_guess(char* name) {
    int index = 0;
    if (count > 0) {
        do {
            if (__stricmp(names[index], name) == 0) {
                return index;
            }
            ++index;
        } while (index < count);
    }
    return -1;
}

struct IndexedTable_guess {
    unsigned char unknown_00[0x0c];
    int* values;
    int count;
    int Get_guess(int index);
};

// Bounds-checked read, 0 outside the array.
// FUNCTION: TITANIUM 0x0040C059
int IndexedTable_guess::Get_guess(int index) {
    if (index < count && index >= 0) {
        return values[index];
    }
    return 0;
}

// EXTERNAL: TITANIUM 0x0060E620 _strncpy
char* __cdecl _strncpy(char* destination, const char* source, unsigned int count);

// strncpy that always terminates: the last of the `count` bytes becomes 0.
// FUNCTION: TITANIUM 0x0040C073
char* __cdecl CopyTerminated_guess(char* destination, const char* source, unsigned int count) {
    _strncpy(destination, source, count);
    destination[count - 1] = '\0';
    return destination;
}

// EXTERNAL: TITANIUM 0x0060E07D _free
void __cdecl _free(void* memory);

// EXTERNAL: TITANIUM 0x0060F317 _malloc
void* __cdecl _malloc(unsigned int size);

// EXTERNAL: TITANIUM 0x0060F0C3 _realloc
void* __cdecl _realloc(void* memory, unsigned int size);

// (Re)allocates a block of `requestedSize` rounded up to `quantum`, with its size in an 8-byte header
// before the returned pointer. Size 0 frees it; a failed realloc returns 0 and leaks nothing.
// FUNCTION: TITANIUM 0x0040C095
int* __cdecl ResizeBuffer_guess(int* buffer, int requestedSize, int quantum) {
    int size = ((requestedSize + quantum - 1) / quantum) * quantum;
    if (size == 0) {
        if (buffer != 0) {
            _free(buffer - 2);
        }
        return 0;
    }

    int* header;
    if (buffer == 0) {
        header = (int*)_malloc(size + 8);
    } else {
        if (size == buffer[-2]) {
            return buffer;
        }
        header = (int*)_realloc(buffer - 2, size + 8);
        if (header == 0) {
            return 0;
        }
    }
    *header = size;
    return header + 2;
}

struct StringRecord_guess {
    char text_00[0x30];
    int value_030;
    char flag_034;
    unsigned char unknown_035[3];
};

// EXTERNAL: TITANIUM 0x00640010 ??_7ChatServerClient_guess@@6B@
struct ChatServerClient_guess {
    virtual ~ChatServerClient_guess();
    ChatServerClient_guess(int a, int b, char* c, char* d, int e, char f, char g, char* h, char i);
    int value_04;                      // 0x04
    VirtualTarget_guess* connection_0008_guess;     // 0x08
    int* values_0c;                    // 0x0c
    int count_10;                      // 0x10
    char flag_14;                      // 0x14
    char flag_15;                      // 0x15
    char flag_16;                      // 0x16
    char flag_17;                      // 0x17
    Owner_guess* target_18;            // 0x18
    char text_01c[0x30];               // 0x1c
    char text_04c[0x30];               // 0x4c
    char text_07c[0x30];               // 0x7c
    char text_0ac[0x10];               // 0xac
    unsigned int length_0bc;           // 0xbc
    int value_0c0;                     // 0xc0
    int value_0c4;                     // 0xc4
    StringRecord_guess** records_0c8;  // 0xc8
    int count_0cc;                     // 0xcc
    void Clear_guess();
    void Set_guess(char* text, int value);
    void DispatchIf_guess(int unused_guess);
    void Parse_guess(int unused_guess, char* data, int size);
};

struct InitSettings_guess {
    int value_00;
    int value_04;
    int value_08;
    int value_0c;
    int value_10;
    int value_14;
    int value_18;
    int value_1c;
    int value_20;
    int value_24;
    int value_28;
    union {
        int value_2c;
        struct {
            unsigned char flag_2c;
            unsigned char flag_2d;
            unsigned char flag_2e;
            unsigned char unknown_2f;
        };
    };
};

struct Config_guess {
    Config_guess();
    int value_00;                      // 0x00
    int value_04;                      // 0x04
    int value_08;                      // 0x08
    int value_0c;                      // 0x0c
    int value_10;                      // 0x10
    int value_14;                      // 0x14
    int value_18;                      // 0x18
    int value_1c;                      // 0x1c
    int value_20;                      // 0x20
    unsigned char flag_24;             // 0x24
    unsigned char flag_25;             // 0x25
    unsigned char flag_26;             // 0x26
    unsigned char unknown_027;         // 0x27
    int value_28;                      // 0x28
    int value_2c;                      // 0x2c
    int value_30;                      // 0x30
    int value_34;                      // 0x34
    int value_38;                      // 0x38
    int value_3c;                      // 0x3c
    int value_40;                      // 0x40
    int value_44;                      // 0x44
    unsigned char flag_48;             // 0x48
    unsigned char unknown_049[0x03];   // 0x49
    int value_4c;                      // 0x4c
    int value_50;                      // 0x50
    int value_54;                      // 0x54
    int value_58;                      // 0x58
    int value_5c;                      // 0x5c
    int value_60;                      // 0x60
    unsigned char flag_64;             // 0x64
    unsigned char flag_65;             // 0x65
    unsigned char unknown_066[0x02];   // 0x66
    int value_68;                      // 0x68
    int value_6c;                      // 0x6c
    unsigned char flag_70;             // 0x70
    unsigned char unknown_071[0x1f];   // 0x71
    union {
        InitSettings_guess settings_90; // 0x90
        struct {
            int value_90;              // 0x90
            int value_94;              // 0x94
            int value_98;              // 0x98
            unsigned char unknown_09c[0x24];
        };
    };
    InitSettings_guess copies_c0[3];   // 0xc0
    int value_150;                     // 0x150
    int value_154;                     // 0x154
    int value_158;                     // 0x158
    unsigned char flag_15c;            // 0x15c
    unsigned char unknown_15d[0x03];   // 0x15d
    int value_160;                     // 0x160
    int value_164;                     // 0x164
    int value_168;                     // 0x168
    int value_16c;                     // 0x16c
};

// Connection defaults: probably the UDP library's parameter block, which the chat client then overrides
// (tu_017 calls it NetConfig_guess). The three copies at +0xC0 repeat the block at +0x90.
// FUNCTION: TITANIUM 0x0040BD15
// @early-stop: budget, diff ndiff=46
Config_guess::Config_guess() {
    value_3c = -1;
    value_5c = -1;
    value_10 = 0x10000;
    value_14 = 0x10000;
    value_18 = 100;
    value_44 = 100;
    value_54 = 1000;
    value_28 = 5000;
    value_68 = 1000;
    value_60 = 5000;
    value_00 = 0;
    value_38 = 50;
    value_40 = 0x200;
    flag_48 = 0;
    value_4c = 0;
    value_164 = 0;
    value_168 = 0;
    value_16c = 0;
    value_1c = 0;
    value_20 = 0;
    value_2c = 0;
    value_04 = 10;
    value_08 = 0;
    value_0c = 0;
    value_58 = 0;
    flag_24 = 1;
    flag_25 = 1;
    flag_26 = 0;
    value_30 = 90000;
    flag_64 = 1;
    flag_65 = 0;
    value_34 = 0;
    value_50 = 10;
    flag_70 = 0;
    value_158 = 0;
    flag_15c = 0;
    value_6c = 20;
    value_160 = 0x1400000;
    value_150 = 0;
    value_154 = 0;
    settings_90.value_08 = 400;
    settings_90.value_00 = 0x32000;
    settings_90.value_04 = 400;
    settings_90.flag_2c = 0;
    settings_90.flag_2d = 1;
    settings_90.flag_2e = 1;
    settings_90.value_0c = 0;
    settings_90.value_18 = 300;
    settings_90.value_1c = 125;
    settings_90.value_20 = 8000;
    settings_90.value_28 = 0;
    settings_90.value_24 = 0;
    settings_90.value_14 = 0;
    settings_90.value_10 = 0;
    for (int i = 0; i < 3; ++i) {
        copies_c0[i] = settings_90;
    }
}

struct Connection_guess {
    unsigned char unknown_000[0x3b0];
    // EXTERNAL: TITANIUM 0x005E9D70 Connection_guess::Connection_guess
    Connection_guess(Config_guess& config);
    // EXTERNAL: TITANIUM 0x005EA440 Connection_guess::Connect_guess
    Owner_guess* Connect_guess(int a, int b, int timeout);
};

// EXTERNAL: TITANIUM 0x0060DA00 memcpy
void* __cdecl memcpy(void* destination, const void* source, unsigned int size);
// EXTERNAL: TITANIUM 0x0060F520 strchr
char* __cdecl strchr(const char* text, int c);
// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

// Chat-server client (CEverQuest +0x290): `a`/`b` the server address, `c` the login name ("server.name"),
// `d` the password, `e` the sink for incoming chat, `f` ChatKeepAlive from eqclient.ini, `h` the locale.
// `c` up to its first '.' becomes the server prefix that is stripped from every name received.
// The `f` test probably picks the keep-alive interval: 14.8 s with ChatKeepAlive, 44 s without.
// FUNCTION: TITANIUM 0x0040C1FA
ChatServerClient_guess::ChatServerClient_guess(int a, int b, char* c, char* d, int e, char f, char g,
                                     char* h, char i) {
    flag_16 = g;
    flag_17 = i;
    value_04 = e;
    count_10 = 0;
    values_0c = 0;
    count_0cc = 0;
    records_0c8 = 0;
    flag_14 = 0;
    CopyTerminated_guess(text_01c, c, 0x30);
    CopyTerminated_guess(text_04c, d, 0x30);
    CopyTerminated_guess(text_0ac, h, 0x10);
    text_07c[0] = 0;
    length_0bc = 0;
    char* dot = strchr(text_01c, 0x2e);
    if (dot != 0) {
        length_0bc = dot - text_01c + 1;
        memcpy(text_07c, text_01c, length_0bc);
        text_07c[length_0bc] = 0;
    }
    Config_guess cfg;
    cfg.value_4c = 0;
    cfg.value_164 = 2;
    cfg.value_44 = 10;
    cfg.value_14 = 0x4000;
    cfg.value_20 = 0;
    cfg.value_1c = 0x39d0;
    if (f == 0) {
        cfg.value_1c = 44000;
    }
    cfg.value_10 = 0x4000;
    cfg.value_04 = 3;
    cfg.value_38 = 0;
    cfg.value_18 = 5;
    cfg.value_08 = 0;
    cfg.value_54 = 0x14;
    cfg.value_98 = 0x18;
    cfg.value_90 = 10000;
    cfg.value_94 = 0x18;
    cfg.value_68 = 5000;
    Connection_guess* conn = new Connection_guess(cfg);
    connection_0008_guess = (VirtualTarget_guess*)conn;
    target_18 = conn->Connect_guess(a, b, 30000);
    if (target_18 != 0) {
        target_18->Set_guess((int)this);
    }
    flag_15 = 0;
    value_0c0 = 0;
    value_0c4 = 0;
}

struct DispatchTarget_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(int unused_guess);
};

// Calls the sink's slot 1 once logged in.
// FUNCTION: TITANIUM 0x0040BFB8
void ChatServerClient_guess::DispatchIf_guess(int unused_guess) {
    if (flag_14 != 0) {
        return ((DispatchTarget_guess*)value_04)->Slot01_guess(unused_guess);
    }
}

// Frees the joined-channel list.
// FUNCTION: TITANIUM 0x0040C3CE
void ChatServerClient_guess::Clear_guess() {
    int index = 0;
    while (index < count_10) {
        free((void*)values_0c[index]);
        ++index;
    }
    ResizeBuffer_guess(values_0c, 0, 1);
    count_10 = 0;
    values_0c = 0;
}

// EXTERNAL: TITANIUM 0x0060DD40 _memmove
void* __cdecl _memmove(void* destination, const void* source, unsigned int size);

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

// Sets the count for `text` in the type-6 list (0x38-byte records); 0 removes it. A new entry is
// flagged when its name has the player's server prefix.
// FUNCTION: TITANIUM 0x0040C405
void ChatServerClient_guess::Set_guess(char* text, int value) {
    int index = 0;
    while (index < count_0cc) {
        if (__stricmp(records_0c8[index]->text_00, text) == 0) {
            records_0c8[index]->value_030 = value;
            CopyText_guess(records_0c8[index], text);
            if (value != 0) {
                return;
            }
            free(records_0c8[index]);
            --count_0cc;
            _memmove(records_0c8 + index, records_0c8 + index + 1,
                     (count_0cc - index) * 4);
            return;
        }
        ++index;
    }
    if (value != 0) {
        records_0c8 = (StringRecord_guess**)ResizeBuffer_guess(
            (int*)records_0c8, count_0cc * 4 + 4, 0x40);
        records_0c8[count_0cc] = (StringRecord_guess*)operator new(0x38);
        CopyText_guess(records_0c8[count_0cc], text);
        records_0c8[count_0cc]->value_030 = value;
        records_0c8[count_0cc]->flag_034 = (char)!_strnicmp(text, text_07c, length_0bc);
        ++count_0cc;
    }
}

// Frees both lists, disconnects and releases the connection, then the connection manager.
// FUNCTION: TITANIUM 0x0040C654
ChatServerClient_guess::~ChatServerClient_guess() {
    Clear_guess();
    int index = 0;
    while (index < count_0cc) {
        free(records_0c8[index]);
        ++index;
    }
    ResizeBuffer_guess((int*)records_0c8, 0, 1);
    if (target_18 != 0) {
        target_18->Flush_guess(0);
        target_18->Slot01_guess();
    }
    connection_0008_guess->Slot01_guess();
}

struct ParseSink_guess {
    virtual void Slot00_guess(bool value);
    virtual void Slot01_guess();
    virtual void Slot02_guess(char* a, char* b, int c, char* d, bool e);
    virtual void Slot03_guess(char* a, char* b, char* c, int d, char* e, bool f);
    virtual void Slot04_guess(char* a, int b, char* c, bool d);
    virtual void Slot05_guess(char* a, int b, char* c, bool d);
    virtual void Slot06_guess(char* a, int b, char* c);
    virtual void Slot07_guess();
    virtual void Slot08_guess(char* text, int value);
    virtual void Slot09_guess(int value, char* text);
    virtual void Slot10_guess(int value);
};

// EXTERNAL: TITANIUM 0x004C4FE3 DuplicateString_guess
int __cdecl DuplicateString_guess(const char* text);

// Chat-server packets, by first byte, to the sink (CEverQuest): 1 login result; 2 the comma-separated
// joined channels; 3 a channel message (channel, sender, text) with channel index -1 for a tell, -2 for
// an unknown channel, -3/-4 for a '$' name (-4 when it is the player's own); 4/9 and 5/10 two pairs of
// notices on a channel; 6 a count for a name; 7 a message with extra data; 8 channel text; 11 a byte and
// text; 12 an int. Server prefixes are stripped from names, and `flag` says the sender is the player.
// Type 7's `rest` subtracts the tail pointer itself from `size`, not its offset; as decompiled
// (early-stop), probably not the original.
// FUNCTION: TITANIUM 0x0040C6B7
// @early-stop: budget, structural ndiff=386
void ChatServerClient_guess::Parse_guess(int unused_guess, char* data, int size) {
    char* cursor;
    char buffer[0x100];
    switch ((unsigned char)data[0]) {
    case 1:
        flag_14 = data[1] != 0;
        ((ParseSink_guess*)value_04)->Slot00_guess(flag_14 != 0);
        break;
    case 2:
        Clear_guess();
        if (size > 2) {
            cursor = data + 1;
            while (*cursor != 0) {
                ParseField_guess(buffer, 0x100, &cursor, 0x2c);
                values_0c = ResizeBuffer_guess(values_0c, count_10 * 4 + 4, 0x40);
                values_0c[count_10] = DuplicateString_guess(buffer);
                ++count_10;
            }
        }
        ((ParseSink_guess*)value_04)->Slot07_guess();
        break;
    case 3: {
        char* name = data + 1;
        char* second = name + strlen(name) + 1;
        char* third = second + strlen(second) + 1;
        bool flag = __stricmp(second, text_01c) == 0;
        if (_strnicmp(second, text_07c, length_0bc) == 0) {
            second += length_0bc;
        }
        if (*name == 0) {
            ((ParseSink_guess*)value_04)->Slot02_guess(third, EQ_ARRAY(char, 0x0063F53F), -1, second, flag);
        } else if (*name == '$') {
            char* text = name + 1;
            if (__stricmp(text, text_01c) == 0) {
                ((ParseSink_guess*)value_04)->Slot02_guess(third, text + length_0bc, -4, second, flag);
            } else {
                if (_strnicmp(text, text_07c, length_0bc) == 0) {
                    text += length_0bc;
                }
                ((ParseSink_guess*)value_04)->Slot02_guess(third, text, -3, second, flag);
            }
        } else {
            char* text = name;
            if (_strnicmp(name, text_07c, length_0bc) == 0) {
                text = name + length_0bc;
            }
            int index = ((NameTable_guess*)this)->Find_guess(text);
            if (index >= 0) {
                ((ParseSink_guess*)value_04)->Slot02_guess(third, text, index, second, flag);
                break;
            }
            ((ParseSink_guess*)value_04)->Slot02_guess(third, text, -2, second, flag);
        }
        break;
    }
    case 4:
    case 9: {
        char* name = data + 1;
        char* second = name + strlen(name) + 1;
        if (_strnicmp(second, text_07c, length_0bc) == 0) {
            second += length_0bc;
        }
        if (_strnicmp(name, text_07c, length_0bc) == 0) {
            name += length_0bc;
        }
        int index = ((NameTable_guess*)this)->Find_guess(name);
        if (index >= 0) {
            ((ParseSink_guess*)value_04)->Slot04_guess(second, index, name, *data == 4);
        }
        break;
    }
    case 5:
    case 10: {
        char* name = data + 1;
        char* second = name + strlen(name) + 1;
        if (_strnicmp(second, text_07c, length_0bc) == 0) {
            second += length_0bc;
        }
        if (_strnicmp(name, text_07c, length_0bc) == 0) {
            name += length_0bc;
        }
        int index = ((NameTable_guess*)this)->Find_guess(name);
        if (index >= 0) {
            ((ParseSink_guess*)value_04)->Slot05_guess(second, index, name, *data == 5);
        }
        break;
    }
    case 6: {
        unsigned char value = data[1];
        char* text = data + 2;
        Set_guess(text, value);
        ((SortableArray_guess*)this)->Sort_guess();
        ((ParseSink_guess*)value_04)->Slot08_guess(text, value);
        break;
    }
    case 7: {
        char* head = data + 1;
        char* mid = head + strlen(head) + 1;
        char* tail = mid + strlen(mid) + 1;
        int rest = size - (int)tail;
        bool flag = __stricmp(mid, text_01c) == 0;
        if (_strnicmp(mid, text_07c, length_0bc) == 0) {
            mid += length_0bc;
        }
        if (*head == 0) {
            ((ParseSink_guess*)value_04)->Slot03_guess(tail, data + rest, EQ_ARRAY(char, 0x0063F53F), -1, mid, flag);
        } else if (*head == '$') {
            char* text = head + 1;
            if (__stricmp(text, text_01c) == 0) {
                ((ParseSink_guess*)value_04)->Slot03_guess(tail, data + rest, text + length_0bc, -4, mid, flag);
            } else {
                if (_strnicmp(text, text_07c, length_0bc) == 0) {
                    text += length_0bc;
                }
                ((ParseSink_guess*)value_04)->Slot03_guess(tail, data + rest, text, -3, mid, flag);
            }
        } else {
            char* text = head;
            if (_strnicmp(head, text_07c, length_0bc) == 0) {
                text = head + length_0bc;
            }
            int index = ((NameTable_guess*)this)->Find_guess(text);
            if (index >= 0) {
                ((ParseSink_guess*)value_04)->Slot03_guess(tail, data + rest, text, index, mid, flag);
                break;
            }
            ((ParseSink_guess*)value_04)->Slot03_guess(tail, data + rest, text, -2, mid, flag);
        }
        break;
    }
    case 8: {
        char* text = data + 1;
        unsigned int len = strlen(text);
        int index = ((NameTable_guess*)this)->Find_guess(text);
        if (index >= 0) {
            ((ParseSink_guess*)value_04)->Slot06_guess(text + len + 1, index, text);
        }
        break;
    }
    case 11: {
        char* text = data + 2;
        ((ParseSink_guess*)value_04)->Slot09_guess((int)data[1], text);
        break;
    }
    case 12:
        ++data;
        memcpy(&size, data, 4);
        ((ParseSink_guess*)value_04)->Slot10_guess(size);
        break;
    }
}

struct QueryResult_guess {
    int unknown_00[5];                 // 0x00
    int value_14;                      // 0x14
    int unknown_18[6];                 // 0x18
};

struct Pump_guess {
    // EXTERNAL: TITANIUM 0x005EB890 Pump_guess::Wait_guess
    void Wait_guess(int milliseconds, int flag);
};

struct Reporter_guess {
    unsigned char unknown_00[0x08];    // 0x00
    Pump_guess* pump_08;               // 0x08
    unsigned char unknown_0c[0x09];    // 0x0c
    char flag_15;                      // 0x15
    char value_16;                     // 0x16
    char value_17;                     // 0x17
    Owner_guess* owner_18;             // 0x18
    char text_1c[0x30];                // 0x1c
    char text_4c[0x60];                // 0x4c
    char text_ac[0x14];                // 0xac
    __int64 timestamp_00c0_guess;                  // 0xc0
    void GiveTime_guess();
};

// Chat client tick (CEverQuest's game loop): once connected, sends the login (type 1: a flag, name,
// password, locale, a byte) once; every 5000 ms reads the connection stats and disconnects when field
// +0x14 is over 30000 (probably ms since the last packet). Then pumps the connection for up to 500 ms.
// FUNCTION: TITANIUM 0x0040C544
// @early-stop: budget, diff ndiff=2
void Reporter_guess::GiveTime_guess() {
    QueryResult_guess result;
    char buffer[0x400];
    if (owner_18 != 0 && owner_18->Get_guess() == 1) {
        if (flag_15 == 0) {
            flag_15 = 1;
            buffer[0] = 1;
            buffer[1] = value_16;
            strcpy(buffer + 2, text_1c);
            char* cursor = buffer + 3 + strlen(text_1c);
            strcpy(cursor, text_4c);
            unsigned int second = strlen(text_4c);
            char* last = &cursor[second + 1];
            strcpy(last, text_ac);
            unsigned int third = strlen(text_ac);
            char* tail = &last[third + 1];
            *tail = value_17;
            owner_18->Append_guess(4, buffer, (unsigned int)(tail + 1 - buffer));
        }
        int elapsed = ClockElapsed_guess(timestamp_00c0_guess);
        if (elapsed > 5000) {
            timestamp_00c0_guess = GetClockStamp_guess();
            owner_18->Query_guess(4, &result);
            if (result.value_14 > 30000) {
                owner_18->Flush_guess(0);
            }
        }
    }
    pump_08->Wait_guess(500, 1);
}

