# Linux Build Notes / Notas de Build Linux

This file is available in both languages:
1. English (first)
2. Español (below)

---

## English

# Linux Build Notes (Usable Phase)

This document summarizes the Linux migration phase for `obs-streamelements-core`.

It includes:
- Packages/libraries installed during this phase.
- Recommended minimum dependencies for building.
- Usage of the `_scripts/build-linux.sh` helper script.

## Scope

Tested on:
- Fedora 43
- OBS 32.1.x
- Qt 6

Validated flow:
- Plugin compiled and integrated as a module in a Linux environment.
- Real streaming tests with both horizontal and vertical scenes.

## Packages Installed in This Phase (Fedora)

During migration, these packages were installed or validated on the system:

- `obs-studio-devel`
- `qt6-qttools-devel`
- `qt6-designer`
- `qt6-linguist`
- `qt6-doctools`
- `qt6-doc-devel`
- `extra-cmake-modules`
- `libavutil-free-devel`
- `libswresample-free-devel`
- `libavcodec-free-devel`
- `libavformat-free-devel`
- `libswscale-free-devel`
- `libpostproc-free-devel`
- `libavfilter-free-devel`
- `swig`
- `vlc-devel`

Note: some packages were installed automatically as `dnf` dependencies.

## Recommended Minimum Dependencies (Fedora)

For a clean build from scratch, we recommend at least:

```bash
sudo dnf install \
  git cmake ninja-build gcc gcc-c++ make pkgconf-pkg-config \
  obs-studio-devel \
  qt6-qtbase-devel qt6-qttools-devel \
  curl-devel swig vlc-devel \
  libavutil-free-devel libswresample-free-devel libavcodec-free-devel \
  libavformat-free-devel libswscale-free-devel libpostproc-free-devel \
  libavfilter-free-devel
```

If you build `obs-studio` from source, also install the dependencies recommended by OBS for your distro.

## Known Conflicts (Fedora + RPMFusion)

During this phase, a common conflict appeared between Fedora FFmpeg variants (`*-free`) and RPMFusion `ffmpeg-libs` while trying to install `x264`:

- Conflict between `libswscale-free` and `ffmpeg-libs`.

Recommendation:
- Do not mix FFmpeg stacks without reviewing package replacements first.
- Keep one consistent package family on the build machine.

## Build Script

Path:

- `_scripts/build-linux.sh`

Permissions:

```bash
chmod +x _scripts/build-linux.sh
```

### Basic usage

```bash
./_scripts/build-linux.sh
```

By default, the script auto-detects an external `obs-browser` checkout at:

- `../obs-browser` (sibling directory of this repository)

If needed, pass it explicitly:

```bash
./_scripts/build-linux.sh --obs-browser-dir ~/Projects/Others/obs-browser
```

### Clean build

```bash
./_scripts/build-linux.sh --clean
```

### Build + install into OBS user plugin directory

```bash
./_scripts/build-linux.sh --clean --install-user
```

This copies:
- `.so` binary to `~/.config/obs-studio/plugins/obs-streamelements-core/bin/64bit/`
- Plugin data to `~/.config/obs-studio/plugins/obs-streamelements-core/data/obs-plugins/obs-streamelements-core/`

### Help

```bash
./_scripts/build-linux.sh --help
```

## Script options

- `--build-dir <path>`: build directory.
- `--build-type <type>`: CMake build type (`RelWithDebInfo`, `Release`, etc).
- `--generator <name>`: CMake generator (default: `Ninja`).
- `--target <name>`: build target (default: `obs-streamelements-core`).
- `--jobs <n>`: build parallelism.
- `--clean`: remove build directory before configure.
- `--no-configure`: skip `cmake -S/-B` and only build.
- `--configure-only`: configure only, do not build.
- `--cmake-arg <arg>`: extra CMake configure argument (repeatable).
- `--install-user`: install compiled plugin in OBS user profile.
- `--user-plugin-dir <path>`: base plugin install path.
- `--obs-browser-dir <path>`: path to an external `obs-browser` checkout.

## Wayland / X11 workaround used in this branch

This branch applies a Linux rendering workaround focused on Wayland:

- The video composition widget uses a **Wayland-only path** in the Linux window bridge.
- **X11 fallback is intentionally disabled** in this branch.

Operational implications:

- Use this branch only in environments where Wayland is expected.
- If OBS is running through X11/XWayland, that path is intentionally not used here.
- The build requires the `obs-browser` changes from this migration, available in the fork `clairerb6/obs-browser`.
- Upstream/official `obs-browser` may not include the required Wayland behavior used by this branch.
- `obs-browser` can be provided via:
  - sibling checkout `../obs-browser` (auto-detected), or
  - `--obs-browser-dir <path>`.

## Runtime troubleshooting (Linux)

If the module appears in logs but SE.Live UI does not initialize, check for:

- `obs-streamelements-core: obs_browser_init_panel() failed`

In this branch, we explicitly keep a Wayland-only runtime strategy.
If that message appears, it indicates browser panel initialization failed even
after the Wayland-first path.

Policy for this branch:
- Do **not** force `QT_QPA_PLATFORM=xcb`.
- Do **not** rely on X11/XWayland as a runtime fallback.
- Validate in a native Wayland OBS session.

## Stability update (2026-04-25)

This branch now includes a stability fix in `obs-streamelements-core` for repeated OBS launches.

- Root cause observed in coredumps: crashes in `linux-pulseaudio.so` (`pa_stream_peek`) during source-type enumeration.
- Mitigation applied: available source type serialization now avoids creating transient audio sources when properties are not requested.
- Result: repeated launches are significantly more stable and no recurring startup crash was reproduced in the latest validation pass.

Current known limitation (not a crash):
- Wayland docked web panels can still intermittently render as black/empty/offset on first attach.
- Current workaround: undock and dock the panel again; after re-docking, panels render correctly in current tests.

Recommended runtime hygiene:
- Keep a single active `obs-browser` plugin build in OBS.
- Avoid loading both distro/system `obs-browser` and custom local `obs-browser` at the same time.

## Useful examples

CI build in separate directory:

```bash
./_scripts/build-linux.sh \
  --build-dir ./build-ci \
  --build-type RelWithDebInfo \
  --jobs 2
```

Compile without reconfiguring:

```bash
./_scripts/build-linux.sh --no-configure --jobs 1
```

Force compiler:

```bash
./_scripts/build-linux.sh \
  --clean \
  --cmake-arg -DCMAKE_C_COMPILER=clang \
  --cmake-arg -DCMAKE_CXX_COMPILER=clang++
```

## GitHub Actions Integration (later)

This script was designed to be reusable from CI. Recommended flow:

1. Checkout repository.
2. Install Linux runner dependencies.
3. Run `_scripts/build-linux.sh --clean --build-dir ./build-ci`.
4. Publish `obs-streamelements-core.so` as an artifact.

## Phase status

- Current status: **usable** on Linux.
- Pending work before “stable” status:
  - finish Wayland docked panel rendering consistency (black/empty intermittent state).
  - reduce remaining warnings.
  - continue auditing intermittent leaks reported during OBS shutdown.

---

## Español

# Notas de Build Linux (Fase Usable)

Este documento resume la fase de migración Linux de `obs-streamelements-core`.

Incluye:
- Paquetes/librerías instalados durante esta fase.
- Dependencias mínimas recomendadas para compilar.
- Uso del script `_scripts/build-linux.sh`.

## Alcance

Probado en:
- Fedora 43
- OBS 32.1.x
- Qt 6

Flujo validado:
- Plugin compilado e integrado como módulo en entorno Linux.
- Pruebas reales de streaming con escenas horizontal + vertical.

## Paquetes Instalados en Esta Fase (Fedora)

Durante la migración se instalaron o validaron estos paquetes en el sistema:

- `obs-studio-devel`
- `qt6-qttools-devel`
- `qt6-designer`
- `qt6-linguist`
- `qt6-doctools`
- `qt6-doc-devel`
- `extra-cmake-modules`
- `libavutil-free-devel`
- `libswresample-free-devel`
- `libavcodec-free-devel`
- `libavformat-free-devel`
- `libswscale-free-devel`
- `libpostproc-free-devel`
- `libavfilter-free-devel`
- `swig`
- `vlc-devel`

Nota: algunos paquetes se instalaron como dependencias automáticas de `dnf`.

## Dependencias Mínimas Recomendadas (Fedora)

Para una build limpia desde cero, recomendamos al menos:

```bash
sudo dnf install \
  git cmake ninja-build gcc gcc-c++ make pkgconf-pkg-config \
  obs-studio-devel \
  qt6-qtbase-devel qt6-qttools-devel \
  curl-devel swig vlc-devel \
  libavutil-free-devel libswresample-free-devel libavcodec-free-devel \
  libavformat-free-devel libswscale-free-devel libpostproc-free-devel \
  libavfilter-free-devel
```

Si trabajas con `obs-studio` desde source, instala además las dependencias indicadas por OBS para tu distro.

## Conflictos Conocidos (Fedora + RPMFusion)

Durante esta fase apareció un conflicto típico entre variantes FFmpeg de Fedora (`*-free`) y `ffmpeg-libs` de RPMFusion al intentar instalar `x264`:

- Conflicto entre `libswscale-free` y `ffmpeg-libs`.

Recomendación:
- No mezclar stacks FFmpeg sin revisar reemplazos.
- Preferir mantener consistente una sola familia de paquetes en la máquina de build.

## Script de Build

Ruta:

- `_scripts/build-linux.sh`

Permisos:

```bash
chmod +x _scripts/build-linux.sh
```

### Uso básico

```bash
./_scripts/build-linux.sh
```

Por defecto, el script autodetecta un checkout externo de `obs-browser` en:

- `../obs-browser` (directorio hermano de este repositorio)

Si hace falta, se puede pasar explícitamente:

```bash
./_scripts/build-linux.sh --obs-browser-dir ~/Projects/Others/obs-browser
```

### Build limpia

```bash
./_scripts/build-linux.sh --clean
```

### Build + instalación en plugin de usuario OBS

```bash
./_scripts/build-linux.sh --clean --install-user
```

Esto copia:
- Binario `.so` a `~/.config/obs-studio/plugins/obs-streamelements-core/bin/64bit/`
- Datos del plugin a `~/.config/obs-studio/plugins/obs-streamelements-core/data/obs-plugins/obs-streamelements-core/`

### Ayuda

```bash
./_scripts/build-linux.sh --help
```

## Opciones del script

- `--build-dir <path>`: carpeta de build.
- `--build-type <type>`: tipo CMake (`RelWithDebInfo`, `Release`, etc).
- `--generator <name>`: generador CMake (por defecto `Ninja`).
- `--target <name>`: target a compilar (por defecto `obs-streamelements-core`).
- `--jobs <n>`: paralelismo para build.
- `--clean`: elimina la carpeta de build antes de configurar.
- `--no-configure`: omite `cmake -S/-B` y solo compila.
- `--configure-only`: solo configura, no compila.
- `--cmake-arg <arg>`: agrega argumentos extra a CMake (repetible).
- `--install-user`: instala plugin compilado en perfil de usuario OBS.
- `--user-plugin-dir <path>`: ruta base de instalación de plugin.
- `--obs-browser-dir <path>`: ruta de un checkout externo de `obs-browser`.

## Workaround Wayland / X11 usado en esta rama

Esta rama aplica un workaround de render Linux enfocado en Wayland:

- El widget de composición de video usa una ruta **solo Wayland** en el bridge de ventana Linux.
- El fallback a **X11 está deshabilitado intencionalmente** en esta rama.

Implicaciones operativas:

- Esta rama debe usarse en entornos donde se espera Wayland.
- Si OBS corre sobre X11/XWayland, ese camino no se utiliza en esta rama.
- La build necesita los cambios de `obs-browser` usados en esta migración, disponibles en el fork `clairerb6/obs-browser`.
- El `obs-browser` oficial/upstream puede no incluir el comportamiento Wayland requerido por esta rama.
- `obs-browser` se puede proveer por:
  - checkout hermano `../obs-browser` (autodetección), o
  - `--obs-browser-dir <path>`.

## Troubleshooting de ejecución (Linux)

Si el módulo aparece en logs pero la UI de SE.Live no termina de inicializar,
busca esta línea:

- `obs-streamelements-core: obs_browser_init_panel() failed`

En esta rama mantenemos estrategia de ejecución **solo Wayland**.
Si aparece ese mensaje, la inicialización del panel de navegador falló incluso
después de intentar la ruta Wayland-first.

Política de esta rama:
- **No** forzar `QT_QPA_PLATFORM=xcb`.
- **No** depender de X11/XWayland como fallback de ejecución.
- Validar en sesión OBS nativa sobre Wayland.

## Actualización de estabilidad (2026-04-25)

Esta rama ahora incluye un fix de estabilidad en `obs-streamelements-core` para lanzamientos repetidos de OBS.

- Causa raíz observada en coredumps: crash en `linux-pulseaudio.so` (`pa_stream_peek`) durante la enumeración de tipos de source.
- Mitigación aplicada: la serialización de tipos de source disponibles evita crear sources de audio transitorios cuando no se piden propiedades.
- Resultado: los lanzamientos repetidos quedaron mucho más estables y no se reprodujo el crash recurrente en la última validación.

Limitación conocida actual (no crash):
- En Wayland, los paneles web acoplados todavía pueden renderizarse en negro/vacíos/desfasados en el primer acople.
- Workaround actual: desacoplar y volver a acoplar el panel; luego del re-acople, en las pruebas actuales renderizan correctamente.

Higiene recomendada de runtime:
- Mantener una sola build activa de `obs-browser` en OBS.
- Evitar cargar al mismo tiempo `obs-browser` de sistema/distro y `obs-browser` local personalizado.

## Ejemplos útiles

Build CI en carpeta separada:

```bash
./_scripts/build-linux.sh \
  --build-dir ./build-ci \
  --build-type RelWithDebInfo \
  --jobs 2
```

Compilar sin reconfigurar:

```bash
./_scripts/build-linux.sh --no-configure --jobs 1
```

Forzar compilador:

```bash
./_scripts/build-linux.sh \
  --clean \
  --cmake-arg -DCMAKE_C_COMPILER=clang \
  --cmake-arg -DCMAKE_CXX_COMPILER=clang++
```

## Integración con GitHub Actions (más adelante)

El script se diseñó para ser reutilizable desde CI. Flujo recomendado:

1. Checkout del repo.
2. Instalación de dependencias del runner Linux.
3. Ejecutar `_scripts/build-linux.sh --clean --build-dir ./build-ci`.
4. Publicar artefacto `obs-streamelements-core.so`.

## Estado de esta fase

- Estado actual: **usable** en Linux.
- Pendiente para estado “estable”:
  - terminar consistencia de render de paneles acoplados en Wayland (negro/vacío intermitente).
  - Reducir warnings residuales.
  - Seguir auditando leaks intermitentes reportados al cierre de OBS.
