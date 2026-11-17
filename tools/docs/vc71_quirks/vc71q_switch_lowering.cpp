// QUIRK: vc71q-switch-lowering
// KEYWORDS: switch, dense, sparse, jump table, byte index, /O1, /O2
// VARIANTS: O1 O2
// FLAGS@O1: /O1
// FLAGS@O2: /O2
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@O1: Dense7 lacks jmp dword ptr
// EXPECT@O1: Dense8 has jmp dword ptr
// EXPECT@O2: Dense3 lacks jmp dword ptr
// EXPECT@O2: Dense4 has jmp dword ptr
// EXPECT@O1: Sparse200 lacks movzx eax, byte ptr
// EXPECT@O2: Sparse200 has movzx eax, byte ptr
// EXPECT@O2: Sparse200 has jmp dword ptr
// EXPECT@O2: Sparse300 lacks movzx eax, byte ptr
int Dense3(int x) { switch(x){case 0:return 37;case 1:return -8;case 2:return 111;default:return -1;} }
int Dense4(int x) { switch(x){case 0:return 37;case 1:return -8;case 2:return 111;case 3:return 5;default:return -1;} }
int Dense7(int x) { switch(x){case 0:return 37;case 1:return -8;case 2:return 111;case 3:return 5;case 4:return 8193;case 5:return -101;case 6:return 227;default:return -1;} }
int Dense8(int x) { switch(x){case 0:return 37;case 1:return -8;case 2:return 111;case 3:return 5;case 4:return 8193;case 5:return -101;case 6:return 227;case 7:return 64;default:return -1;} }
int Sparse200(int x) { switch(x){case 0:return 173;case 3:return -17;case 6:return 9001;case 200:return 34;default:return -1;} }
int Sparse300(int x) { switch(x){case 0:return 173;case 3:return -17;case 6:return 9001;case 300:return 34;default:return -1;} }
