<script lang="ts">
  import Link from './Link.svelte';
</script>

<svelte:head>
  <!-- meta desc -->
  <meta
    name="description"
    content="Roblox Client Optimizer - A tool to optimize Roblox's client"
  />
  <!-- meta kw -->
  <meta name="keywords" content="Roblox, Client, Optimizer, RCO, L8X, Expo" />
  <!-- meta img /rco.png -->
  <meta
    property="og:image"
    content="https://raw.githubusercontent.com/L8X/Roblox-Client-Optimizer/main/rco.png"
  />
  <!-- meta img alt -->
  <meta property="og:image:alt" content="RCO Logo" />
  <!-- meta img type -->
  <meta property="og:image:type" content="image/png" />
  <!-- meta theme colour -->
  <meta name="theme-color" content="#ff3333" />
</svelte:head>

<div class="header">
  <div>
    <Link to="/">RCO</Link>
    <Link to="/download">Download</Link>
  </div>
  <div>
    <Link to="/source">Source</Link>
    <Link to="/discord">Discord</Link>
  </div>
</div>
<div id="appRoot">
  <slot />
</div>

<style lang="scss">
  #appRoot,
  .header {
    // no blinding ppl
    background: #1a1a1a;
    color: #ffffff;
    // remove ugly default fonts
    font-family: Inter, 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; // Inter is imported in app.html
    // positioning
    position: fixed;
    left: 0;
    // display control
    width: 100vw;
  }
  .header {
    // positioning
    top: 0;
    // display control
    height: 40px;
    // flex shenangians
    display: flex;
    align-items: center;
    justify-content: center;
    gap: 1ch;
    & > div {
      width: calc(50% - 0.5ch - 10px);
      display: flex;
      align-items: center;
      gap: 1ch;
      :global(a) {
        color: #ffffff;
        font-size: 1.2rem;
      }
      :global(a[data-active='true']) {
        font-weight: 600;
      }
      &:first-child {
        text-align: left;
        justify-content: top;
      }
      &:last-child {
        text-align: right;
        justify-content: end;
        @media screen and (max-width: 360px) {
          pointer-events: none;
          opacity: 0;
          visibility: hidden;
        }
      }
    }
  }
  #appRoot {
    // positioning
    top: 40px;
    // display control
    min-height: calc(100vh - 40px);
    // overflow control
    overflow-y: auto;
    overflow-x: hidden;
    // center everything
    display: flex;
    align-items: center;
    justify-content: center;
    flex-direction: column;
  }
  :global(a:not(.no-style)) {
    color: #6633ff;
    text-decoration: none;
    &:hover {
      text-decoration: underline;
    }
  }
</style>
