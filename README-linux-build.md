# Linux Build Notes (Fase Usable)

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

Flujo usado:
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

- conflicto entre `libswscale-free` y `ffmpeg-libs`

Recomendación:
- no mezclar stacks FFmpeg sin revisar reemplazos.
- preferir mantener consistente una sola familia de paquetes en la máquina de build.

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

### Build limpia

```bash
./_scripts/build-linux.sh --clean
```

### Build + instalación en plugin de usuario OBS

```bash
./_scripts/build-linux.sh --clean --install-user
```

Esto copia:
- binario `.so` a `~/.config/obs-studio/plugins/obs-streamelements-core/bin/64bit/`
- datos del plugin a `~/.config/obs-studio/plugins/obs-streamelements-core/data/obs-plugins/obs-streamelements-core/`

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

## Ejemplos Útiles

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
  - reducir warnings residuales.
  - seguir auditando leaks intermitentes reportados al cierre de OBS.
