# NeoCore Migration Sample v2.0.0

## 🧪 For NeoCore Developers Only

**This repository is exclusively intended for NeoCore framework developers to test migration scenarios from v2**

## Purpose

This sample project serves as a **controlled testing environment** for validating the NeoCore  migration script (`_upgrade.ps1`). It contains:

- **Authentic v2 project structure** with legacy patterns
- **Deliberately outdated code** that triggers v2/v3 compatibility issues
- **Deprecated files** that should be automatically removed during migration
- **Test scenarios** for comprehensive migration validation

## Repository Structure

```
neocore_migration_sample_2_0_0/
├── README.md                   # This file
├── .gitignore                  # Git ignore patterns
├── upgrade.bat                 # Migration script launcher
├── neocore/                    # NeoCore v2.x framework files
│   ├── src-lib/               # Legacy NeoCore library
│   ├── toolchain/             # Build tools and utilities
│   └── manifest.xml           # Framework version manifest
└── src/                       # Sample project source
    ├── project.xml            # v2 project configuration
    ├── main.c                 # C code with v2 patterns
    ├── Makefile               # Legacy build configuration
    ├── common_crt0_cd.s       # DEPRECATED - should be removed
    ├── crt0_cd.s              # DEPRECATED - should be removed
    ├── mak.bat                # Build script (Windows)
    ├── mak.ps1                # Build script (PowerShell)
    └── assets/                # Sample game assets
```

## Migration Test Scenarios

### 🎯 **Primary Test Cases**

1. **Project.xml Migration**
   - Legacy v2 structure → Modern v3 structure
   - Platform element addition
   - Sound section migration: `<sound>` → `<sound><cd>` structure
   - Build path configurations
   - Version updates

2. **C Code Compatibility Analysis**
   - Detection of v2-specific API calls
   - Function signature changes
   - Deprecated type usage
   - Legacy include patterns

3. **File Management**
   - Automatic removal of deprecated `.s` files
   - Makefile updates
   - NeoCore framework file synchronization

4. **Build System Integration**
   - Validation of migrated project compilation
   - Build script functionality

### 🔍 **Embedded Test Patterns**

The `main.c` file contains **intentionally outdated patterns** designed to trigger migration detection:

```c
// These patterns should be detected by the migration script:
nc_palette_load(0, "mypalette.pal");        // v2 pattern
nc_sound_play_wav("mysound.wav");           // v2 pattern
nc_gfx_load_sprite_old(10, "sprite.spr");   // v2 pattern
nc_draw_sprite_deprecated(100, 100, 0);     // v2 pattern
nc_palette_set_color_old(1, 0xFF0000);      // v2 pattern
nc_input_get_old();                         // v2 pattern
nc_timer_wait_old(60);                      // v2 pattern
```

## Usage Instructions

### � **Setup Requirements**

Before running tests, you may need to **update the paths** in `upgrade.bat` to match your local environment, or simply use the main migration entry point:

```bash
../../bootstrap/scripts/project/upgrade.bat -projectSrcPath .\src -projectNeocorePath .\neocore
```

### �🚀 **For NeoCore Developers**

1. **Clone this repository** as a standalone test environment
2. **Run the migration script** using the main entry point:
   ```bash
   ../../bootstrap/scripts/project/upgrade.bat -projectSrcPath .\src -projectNeocorePath .\neocore
   ```
   *Or use the local shortcut (if paths are configured correctly):*
   ```bash
   upgrade.bat
   ```

   **Alternative (Manual execution):**
   ```bash
   ../../bootstrap/scripts/project/upgrade.bat -projectSrcPath .\src -projectNeocorePath .\neocore
   ```
3. **Analyze the results** to validate migration functionality
4. **Reset the repository** for additional test runs

### 🔄 **Migration Validation Checklist**

After running the migration script, verify:

- [ ] `project.xml` has been converted to v3 format
- [ ] C code analysis detected all embedded v2 patterns
- [ ] Deprecated `.s` files were automatically removed
- [ ] Makefile was updated to v3 version
- [ ] NeoCore framework files were synchronized
- [ ] Migration log contains detailed analysis results
- [ ] Project can be built successfully with `mak build`

## Expected Migration Results

### ✅ **Successful Migration Indicators**

- **Dynamic Action Report**: Should show categorized C code issues
- **File Updates**: Makefile, mak.bat, mak.ps1 updated automatically
- **Cleanup**: `common_crt0_cd.s` and `crt0_cd.s` removed
- **Backup Creation**: UUID-based project backup created
- **Log Generation**: Comprehensive migration.log with all operations

### 📊 **Expected Issue Categories**

The migration should detect and categorize:

1. **Legacy API Calls** (7+ issues in main.c)
2. **Deprecated Functions** (Various counts)
3. **Type System Changes** (If Vec2short patterns present)
4. **Project Structure Issues** (project.xml format)

## Important Notes

### ⚠️ **Development Use Only**

- This repository is **NOT a production template**
- Contains **deliberately outdated code patterns**
- Designed specifically for **migration testing purposes**
- Should **NOT be used as a reference** for new NeoCore projects

### 🔧 **Maintenance**

- Keep this repository in sync with known v2 patterns
- Update test cases as migration script evolves
- Maintain as a **frozen v2 snapshot** for consistent testing
- Reset to original state after each test run

### 📝 **Testing Documentation**

When using this repository for testing:

1. Document any migration issues discovered
2. Note performance metrics and timing
3. Validate all expected patterns are detected
4. Verify clean migration without errors
5. Test post-migration build functionality

## Related Documentation

- **NeoCore Repository**: https://github.com/David-Vandensteen/neocore
- **Migration Guide**: `MIGRATION_GUIDE_v2Tov3.md` in main repository
- **Migration Script**: `bootstrap/scripts/project/upgrade.bat`
- **NeoCore v3 Documentation**: Main repository README files

---

**For questions about this test repository, contact the NeoCore development team.**

**Last Updated**: August 2025
**NeoCore Version**: 3.0.0 development branch
**Purpose**: Migration testing and validation
