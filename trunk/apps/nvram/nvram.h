struct nvram_t {
	char name[40];
	char value[192];
};

//extern int nvram_init(void);
int nvram_show(void);
int nvram_upgrade(void);
char *nvram_get(const char *name);
char *nvram_safe_get(const char *name);
int nvram_set(const char *name, const char *value);
int nvram_unset(const char *name);
int nvram_del(const char *name);
int nvram_count(const char *name);
int nvram_match(const char *name, const char *value);
int nvram_commit(void);
int nvram_restore_default(void);
int nvram_config2file(void);
int nvram_file_save(const char *name, const char *file);
int nvram_file_restore(const char *name, const char *file);
int nvram_replace(const char *name, const char *value);

void nvram_flag_reset(void);

#ifdef CONFIG_VLAN_ROUTER
#define CONF_BUF 30*1024
#else
#define CONF_BUF 30*1024
#endif  
  
#ifndef CONFIG_NVRAM_BLK
#define CONFIG_NVRAM_BLK "/dev/mtdblock1"
#endif

#ifdef ATHEROS_11N_DRIVER  
#define SYS_CONF_MTDBLK CONFIG_NVRAM_BLK
#else
#define SYS_CONF_MTDBLK "/dev/mtdblock/1"
#endif

#define NVRAM_FILE "/var/etc/nvram.conf"
#define NVRAM_SIZE_COUNT "/var/etc/nvram_count.txt"

