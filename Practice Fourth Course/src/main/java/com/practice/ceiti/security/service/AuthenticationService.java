package com.practice.ceiti.security.service;

import com.practice.ceiti.security.dao.model.Account;
import com.practice.ceiti.security.dao.repository.AccountRepository;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.Collection;

@Service
public class AuthenticationService implements UserDetailsService {

    private final AccountRepository accountRepository;

    public AuthenticationService(AccountRepository accountRepository) {
        this.accountRepository = accountRepository;
    }

    @Override
    public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
        Account account = accountRepository.findOneByUsername(username);
        if (account == null) {
            throw new UsernameNotFoundException("No such user in the system : " + username);
        }
        return createUser(account);
    }

    private User createUser(Account account) {
        return new User(account.getUsername(), account.getPassword(), createAuthorities(account));
    }

    private Collection<GrantedAuthority> createAuthorities(Account account) {
        Collection<GrantedAuthority> authorities = new ArrayList<>();
        authorities.add(new SimpleGrantedAuthority("ROLE_" + account.getRole()));
        return authorities;
    }

}
