# ==================== PROJECT OPTIONS ====================

TARGET   := $(notdir $(CURDIR))
SOURCES  := src
INCLUDES := include
BUILD    := build

CC := gcc
CFLAGS := -Wall -std=c99
LD := $(CC)
LDFLAGS := $(CFLAGS)

vpath %.c $(SOURCES)
vpath %.h $(INCLUDES)

CFILES := $(foreach dir, $(SOURCES), $(notdir $(wildcard $(dir)/*.c)))
HFILES := $(foreach dir, $(INCLUDES), $(wildcard $(dir)/*.h))
OFILES := $(CFILES:.c=.o)
OUTPUT := $(CURDIR)/$(TARGET)

$(OUTPUT).elf : $(OFILES)
	$(LD) $(LDFLAGS) $(BUILD)/* -o $@

$(OFILES) : %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(BUILD)/$@

$(CFILES) : $(HFILES)


$(OFILES): | $(BUILD)


$(BUILD):
	@mkdir $@

# ============== CLEAN ======================
clean:
	@rm -rf $(BUILD) $(TARGET).elf

.PHONY: $(BUILD) clean
