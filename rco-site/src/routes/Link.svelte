<script lang="ts">
  import { page } from '$app/stores';
  export let to: string;
</script>

<a href={to} data-active={$page.url.pathname === to}><slot /></a>
