# ==================== PROJECT OPTIONS ====================

TARGET  := $(notdir $(CURDIR))
SOURCES := src
INCLUDES := include
BUILD   := build

CC := gcc
CFLAGS := -Wall -std=c99
LD := $(CC)
LDFLAGS := $(CFLAGS)

# ==================== BUILDING PROCESS ====================

ifneq ($(BUILD),$(notdir $(CURDIR)))

export CFILES := $(foreach dir, $(SOURCES), $(wildcard $(CURDIR)/$(dir)/*.c))
export OFILES   := $(notdir $(CFILES:.c=.o))
export OUTPUT := $(CURDIR)/$(TARGET)

$(BUILD) :
	@[ -d $@ ] || mkdir -p $@
	@$(MAKE) -C $(BUILD) -f $(CURDIR)/Makefile

else

$(OUTPUT).elf : $(OFILES)
	$(LD) $(LDFLAGS) $^ -o $@

$(OFILES) : $(CFILES)
	$(CC) $(CFLAGS) -c $< -o $@

endif

# ============== CLEAN ======================
clean:
	@rm -rf $(BUILD) $(TARGET).elf

.PHONY: $(BUILD) clean
