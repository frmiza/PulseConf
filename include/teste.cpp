#include <stdio.h>
#include <string.h> // Para strstr()
#include <pulse/pulseaudio.h>

// Sinalizadores globais para encerrar o programa
int done_sources = 0;
int done_sinks = 0;

// Callback para listar dispositivos de entrada (sources)
void source_info_callback(pa_context *context, const pa_source_info *info, int eol, void *userdata) {
    if (eol > 0) {
        done_sources = 1; // Final da lista de sources
        return;
    }

    // Ignorar dispositivos de monitor (contêm "monitor" no nome)
    //if (strstr(info->name, "monitor")) {
    //    return;
    //}

    // Exibir informações da source
    printf("== Dispositivo de Entrada ==\n");
    printf("Nome: %s\n", info->name);
    printf("Descrição: %s\n", info->description);
    printf("Driver: %s\n", info->driver);

    // Status do dispositivo de entrada
    const char *state;
    switch (info->state) {
        case PA_SOURCE_RUNNING:
            state = "Ativo";
            break;
        case PA_SOURCE_IDLE:
            state = "Inativo";
            break;
        case PA_SOURCE_SUSPENDED:
            state = "Suspenso";
            break;
        default:
            state = "Desconhecido";
            break;
    }
    printf("Estado: %s\n", state);

    // Listar portas e identificar a porta ativa
    if (info->ports) {
        printf("Portas:\n");
        for (pa_source_port_info **port = info->ports; *port != NULL; ++port) {
            printf("  - Nome: %s\n", (*port)->name);
            printf("    Descrição: %s\n", (*port)->description);
            if (info->active_port == *port) {
                printf("    [Porta ativa]\n");
            }
        }
    }

    printf("---\n");
}

// Callback para listar dispositivos de saída (sinks)
void sink_info_callback(pa_context *context, const pa_sink_info *info, int eol, void *userdata) {
    if (eol > 0) {
        done_sinks = 1; // Final da lista de sinks
        return;
    }

    // Exibir informações do sink
    printf("== Dispositivo de Saída ==\n");
    printf("Nome: %s\n", info->name);
    printf("Descrição: %s\n", info->description);
    printf("Driver: %s\n", info->driver);

    // Status do dispositivo de saída baseado no volume
    const char *state = (info->mute || pa_cvolume_is_muted(&info->volume)) ? "Inativo" : "Ativo";
    printf("Estado: %s\n", state);

    // Listar portas e identificar a porta ativa
    if (info->ports) {
        printf("Portas:\n");
        for (pa_sink_port_info **port = info->ports; *port != NULL; ++port) {
            printf("  - Nome: %s\n", (*port)->name);
            printf("    Descrição: %s\n", (*port)->description);
            if (info->active_port == *port) {
                printf("    [Porta ativa]\n");
            }
        }
    }

    printf("---\n");
}

// Callback para eventos de estado
void state_callback(pa_context *context, void *userdata) {
    pa_context_state_t state = pa_context_get_state(context);
    if (state == PA_CONTEXT_READY) {
        // Quando o contexto estiver pronto, solicite informações dos dispositivos de entrada (sources)
        pa_operation *op_sources = pa_context_get_source_info_list(context, source_info_callback, NULL);
        if (op_sources) {
            pa_operation_unref(op_sources);
        }

        // Também solicite informações dos dispositivos de saída (sinks)
        pa_operation *op_sinks = pa_context_get_sink_info_list(context, sink_info_callback, NULL);
        if (op_sinks) {
            pa_operation_unref(op_sinks);
        }
    }
}

int main() {
    // Cria o loop principal do PulseAudio
    pa_mainloop *mainloop = pa_mainloop_new();
    pa_mainloop_api *api = pa_mainloop_get_api(mainloop);
    pa_context *context = pa_context_new(api, "PulseAudio Devices");

    // Configura os callbacks
    pa_context_set_state_callback(context, state_callback, NULL);
    pa_context_connect(context, NULL, PA_CONTEXT_NOFLAGS, NULL);

    // Executa o loop principal até que ambos os sinalizadores sejam definidos
    while (!(done_sources && done_sinks)) {
        pa_mainloop_iterate(mainloop, 1, NULL);
    }

    // Limpa recursos
    pa_context_disconnect(context);
    pa_context_unref(context);
    pa_mainloop_free(mainloop);

    return 0;
}
