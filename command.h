#define CMD_GET_FW_VERSION		0xb0
#define CMD_START			0xb1
#define CMD_GET_REVID_VERSION		0xb2

#define CMD_START_FLAGS_SUPERWIDE_POS   3
#define CMD_START_FLAGS_CLK_CTL2_POS    4
#define CMD_START_FLAGS_WIDE_POS        5
#define CMD_START_FLAGS_CLK_SRC_POS     6

#define CMD_START_FLAGS_CLK_CTL2        (1 << CMD_START_FLAGS_CLK_CTL2_POS)
#define CMD_START_FLAGS_SAMPLE_8BIT     (0 << CMD_START_FLAGS_WIDE_POS)
#define CMD_START_FLAGS_SAMPLE_16BIT    (1 << CMD_START_FLAGS_WIDE_POS)
#define CMD_START_FLAGS_SAMPLE_24BIT    ((0 << CMD_START_FLAGS_WIDE_POS) | (1 << CMD_START_FLAGS_SUPERWIDE_POS))
#define CMD_START_FLAGS_SAMPLE_32BIT    ((1 << CMD_START_FLAGS_WIDE_POS) | (1 << CMD_START_FLAGS_SUPERWIDE_POS))

#define CMD_START_FLAGS_CLK_30MHZ       (0 << CMD_START_FLAGS_CLK_SRC_POS)
#define CMD_START_FLAGS_CLK_48MHZ       (1 << CMD_START_FLAGS_CLK_SRC_POS)
#define CMD_START_FLAGS_CLK_192MHZ      (2 << CMD_START_FLAGS_CLK_SRC_POS)

struct version_info {
        uint8_t major;
        uint8_t minor;
};

struct cmd_start_acquisition {
        uint8_t flags;
        uint8_t sample_delay_h;
        uint8_t sample_delay_l;
};
