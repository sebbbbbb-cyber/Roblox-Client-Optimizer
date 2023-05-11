<script lang="ts">
  import { onMount } from 'svelte';

  let anchor: HTMLAnchorElement;
  onMount(async () => {
    if (!anchor) while (!anchor) await new Promise((r) => setTimeout(r, 100));
    anchor.click();
  });
</script>

<svelte:head>
  <title>RCO - Download</title>
</svelte:head>

<main>
  Not getting prompted to download?<br />
  Click
  <a
    href="/RCO2Installer.exe"
    download="RCO3Installer.exe"
    data-sveltekit-reload
    bind:this={anchor}
  >
    here</a
  >.
  <div style="height:10px" />
  <a
    href="#back"
    on:click={() => history.back()}
    on:keypress={() => history.back()}>Go Back</a
  >
</main>

<style lang="scss">
  main {
    text-align: center;
  }
</style>
